; The bios will load the first configured bootable sector at address 0x7C00 tell NASM to
; use 0x7C00 as the first instruction.
org 0x7C00

bits 16

msg db ""

Start:
cli                     ; Clear the interrupts.
hlt                     ; Halt the processor.

; Now we need to write the bootable signature at the 510th byte (the signature is 2 bytes (0xAA55)..
; $ represents the current line of execution.
; $$ Represents the first line of execution (0x7C00).
; ($-$$) = (currentLine - firstLine)
; It subtracts the first line from the current line which gives you the the amount of bytes currently used.
; The times instruction will do an operation n times: times (n) instruction.
; if the program is 8 bytes the the operation will be: times 510 - (7C08-7C00) db 0.
times 510 - ($-$$) db 0 ; Zero 510 bites minus the existing bites.

; We are now at the 510th byte of the program, we have only 2 bytes left that will be copied to memory.
; These bytes should contain a signature 0xAA55 to tell the bios this is an bootable sector.
dw 0xAA55               ; Bootable signature.
