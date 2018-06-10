;__________________________________________________________________________________________/ bootloader.asm    
;   Author: Joris Rietveld  <jorisrietveld@gmail.com>
;   Created: 08-06-2018 17:45
;   
;   Description:
;
[bits 16]

jmp Bootloader

%include 'util16/common.inc'

kernel_base equ 0x100
boot_device equ 0x0

Bootloader:
    mov ax, 0x90
    mov ds, ax

    mov si,


