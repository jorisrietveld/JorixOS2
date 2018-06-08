;__________________________________________________________________________________________/ a20.asm    
;   Author: Joris Rietveld  <jorisrietveld@gmail.com>
;   Created: 07-06-2018 14:19
;   
;   Description:
;
[bits 16]

%ifndef __A20_INC_INCLUDED__
%define __A20_INC_INCLUDED__

%include 'intel16/jorix_debug.inc'

check_a20:
    pushf                               ; Save the EFLAGS register on stack.
    push ds                             ; Save the data segment.
    push es                             ; Save the extra segment.
    push di                             ; Save the data index.
    push si                             ; save the source index.

    cli                                 ; Disable external interrupts.

    xor ax, ax                          ; Clear the ax.
    mov es, ax                          ; Copy null to the extra segment.

    not ax                              ; Negate 0 to 0xFFFF
    mov ds, ax                          ; Set the data segment to 0xFFFF

    mov di 0x0500                       ; Set the address of boot signature.
    mov si 0x0510                       ; Set the address of the boot signature 1 MiB higher.

    mov al,byte [es:di]                 ; Get the value from es:di.
    push ax                             ; Store the value on to the stack.

    mov al, byte [ds:si]                ; Get the value from ds:si.
    push ax                             ; Store the value on to the stack.

    mov byte [es:di], 0x00              ; Set 0x00 in es:di
    mov byte [ds:si], 0xFF              ; Set 0xFF in ds:si

    cmp byte [es:di], 0xFF              ; Check if the es:di still is zero.

    pop ax                              ; Get the stored ds:si from the stack.
    mov byte [ds:si], al                ; And copy the lower bit of the value and store it into ds:si.

    pop ax                              ; Get the stored es:di from the stack.
    mov byte [es:di], al                ; And copy the lower bit of the value and store it into es:di.

    mov ax, 0                           ; Set the return code to zero in ax if the A20 line is disabled.
    je .return                          ; Check if the two values are the same, if so return a 0.

    mov ax, 1                           ; The values differ from each other so the A20 line is enabled.

    ; Return to the caller.
    .return:
        pop si                          ; Restore the segment index,
        pop di                          ; Data index,
        pop es                          ; Extra segment,
        pop ds                          ; Data segment
        popf                            ; and the EFLAGS registers there previous state.
        ret                             ; And return to the caller.

enable_a20_bios:
    ; Test if BIOS interrupt 15 for switching A20 is supported.
    mov ax, A20_SUPPORT                 ; Get test A20 support command, 0x2403.
    int BIOS_INTRUPT_MIC_SYS            ; Perform an miscellaneous system interrupt, 0x15.
    jb .a20_not_supported               ; When the A20 command isn't recognized it sets the carry flag so jump here.
    cmp ah, 0                           ;
    jnz .a20_not_supported              ;

    ; Check the current status of the a20 gate.
    mov ax, A20_STATUS                  ;
    int BIOS_INTRUPT_MIC_SYS            ;
    jb .a20_status_unavailable          ;
    cmp ah, 0                           ;
    jnz .a20_status_unavailable         ;

    cmp al, 1                           ;
    jz .a20_status_activated            ;

    ; Activate the A20 gate.
    mov ax, A20_ACTIVATE                ;
    int BIOS_INTERUPT_MIC_SYS           ;
    jb .a20_activation_failed           ;
    cmp ah, 0                           ;
    jnz .a20_activation_failed          ;

    .a20_status_activated:
        mov ax, 1                       ;
        ret                             ;

    .a20_status_unavailable:
        ; Possible debug message.
    .a20_activation_failed:
        ; Possible debug message.
        mov ax, 0
        ret

enable_a20_keyboard:
    cli                                 ;
    call a20_wait
%endif ; __A20_INC_INCLUDED__
