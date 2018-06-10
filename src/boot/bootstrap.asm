[bits 16]

jmp Initialize

; Included libraries
%include "intel16/common.inc"
%include "intel16/utils.inc"
%include "intel16/a20.inc"

; Variables and Data
bootdevice equ 0
sectors equ 1

;_________________________________________________________________________________________________________________________/ Initialize
;   Description:
;   Initialize the bootloader by setting up the data en stack segment.
;
Initialize:
    ; Initialize the stack after the bootloader code and buffer.
    mov ax, 0x07C0                      ; Initialize the stack at 0x9C0
    add ax, 0x120                       ; (4096 + 512 ) / 16 bytes per paragraph.
    cli                                 ; Clear the interrupts before moving the stack.
    mov ss, ax                          ; Set the stack segment to 19C0:1000
    mov sp, 4096                        ; Allow it to grow to 4k.
    sti                                 ; Re-enable the interrupts.

    ; Set the data segment to 0x7C0 where the bios has loaded us.
    mov ax, 0x7C0                       ; Get the address where the bios will load us.
    mov ds, ax                          ; Set the data segment to that address.

    ; Hide the cursor with an BIOS video services interrupt.
    mov ah, 0x01                        ; Video services, set video mode code.
    mov cx, 0x2607                      ; Set video mode parameter to hide the cursor.
    int 0x10                            ; Execute the interrupt to hide the cursor.

;_________________________________________________________________________________________________________________________/ EnableA20
;   Description:
;   Enable the A20 line
;
EnableA20:
    call CheckA20                       ; Check if the A20 gate is already enabled.
    call enable_a20_bios                ; Try to enable the A20 gate with an BIOS interrupt.
    call CheckA20                       ; Check if the BIOS interrupt worked.
    call enable_a20_keyboard            ; No luck, try writing to the keyboard (PC/2) controller.
    call CheckA20                       ; Check if writing to the keyboard controller worked.
    call enable_a20_fast                ; Running out of options, try it the dangerous way that can blank the monitor.
    call CheckA20                       ; Check if writing to the System Control Port worked...

    ; In your case, switching the A20 gate might involve black magic.
    .giveUp:
        ;println_16 msg_fatal            ; Notify the user that the system is unable to boot.
        jmp HeatDeathOfTheUniverse      ; Halt the processor until this moment.

CheckA20:
    call check_a20                      ; Check if the A20 line is enabled.
    cmp ax, 1                           ; does check_a20 return a one?
    je LoadStage2                       ; The BIOS enabled it for us, tnx!
    ret                                 ; That did'nt work return to the caller.

LoadStage2:
    .resetDisk:
        xor ax, ax                      ; Clear to use as a reset argument for the low level disk services interrupt.
        xor ah, ah                      ;
        mov dl, 0                       ;
        int BIOS_INTERRUPT_DISK         ;
        jc DiskResetFailed              ;

        mov ax, 0x90                    ; Get the address 0x90
        mov es, ax                      ; Set the extra segment at location 0x90
        xor dx, dx                      ; Move the data segment to 0

    .readSectors:
        mov ah, 0x02                    ; Set the disk interrupt function to read sectors from disk.
        mov al, sectors                 ; Number of sectors to read from the disk.
        xor ch, ch                      ; The cylinder number, xor to make it cylinder 0.
        mov cl, 0x02                    ; Sector 2
        xor dh, dh                      ; The head to use, xor to make it head 0.
        mov dl, bootdevice              ; The drive number to read from.
        int BIOS_INTERRUPT_DISK         ; Read the sectors from the disk with the disk services interrupt.
        jc ReadingSectorsFailed         ;
        cmp al, sectors                 ;
        jne ReadingSectorsFailed        ;

    .runStage2:
        jmp dword 0x90:00                   ;

DiskResetFailed:
ReadingSectorsFailed:
HeatDeathOfTheUniverse:
    cli                     ; Clear the interrupts.
    hlt                     ; Halt the processor.

times 510 - ($-$$) db 0 ; Zero 510 bites minus the existing bites.
dw 0xAA55               ; Bootable signature.
