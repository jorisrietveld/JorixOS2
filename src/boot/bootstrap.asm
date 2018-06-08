[bits 16]

jmp start

%include "intel16/utils.inc"
%include "intel16/types.inc"

start:
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

EnableA20:
    in al, 0x92                         ;
    or al, 2                            ;
    out 0x92, al                        ;

PrintMenu:
    newline_16                          ; Print an new line above the menu header.
    print_16 header_border              ; Print the top border of the menu header.
    print_16 header_text                ; Print the Title of the menu header.
    print_16 header_border              ; Print the Bottom border of the menu header.
    newline_16                          ; Print an margin between the menu header and the menu.





; Variables and data.
string header_border, '========================================'
string header_text, '=  Welcome to the JorixOS2 Bootloader  ='
string message_press_key, 'Press any key to load the second stage...'
string msg_load_stage2, 'Attempt to load the second stage.'
string msg_error_disk_reset, 'Reset disk failed.'
string msg_error_disk_read, 'Read disk failed.'
string msg_error_load_stage2, 'Loading stage 2 failed.'



cli                     ; Clear the interrupts.
hlt                     ; Halt the processor.

times 510 - ($-$$) db 0 ; Zero 510 bites minus the existing bites.
dw 0xAA55               ; Bootable signature.
