; The bios will load the first configured bootable sector at address 0x7C00 tell NASM to
; use 0x7C00 as the first instruction.
org 0x7C00

bits 16

msg db ""

Start:
cli                     ; Clear the interrupts.
hlt                     ; Halt the processor.

times 510 - ($-$$) db 0 ; Zero 510 bites minus the existing bites.
dw 0xAA55               ; Bootable signature.
