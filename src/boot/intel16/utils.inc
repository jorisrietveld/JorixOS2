;__________________________________________________________________________________________/ utils.inc
;   Author: Joris Rietveld  <jorisrietveld@gmail.com>
;   Created: 03-06-2018 02:59
;   
;   Description:
;
[bits 16]

%ifndef __UTILS_INC_INCLUDED__
%define __UTILS_INC_INCLUDED__

;%include 'intel16/ascii.inc'
;%include 'intel16/bios.inc'
;%include 'intel16/jorix_debug.inc'
%include 'intel16/common.inc'

NEWLINE db 0x0A, 0x0D, 0                ;

%macro print_16 1
    mov si, word %1                     ;
    call decl_print_16                  ;
%endmacro

%macro println_16 1
    mov si, word %1                     ;
    call decl_print_16                  ;
    print_16 NEWLINE                    ;
%endmacro

%macro newline_16 0
    print_16 NEWLINE                    ;
%endmacro

key_wait:
    mov al, 0xD2                        ;
    out 0x64, al                        ;

    mov al, 0x80                        ;
    out 0x60, al                        ;

    .keyup:
        in al, 0x60                     ;
        and al, 10000000b               ;

decl_print_16:
    .charLoop:
        lodsb
        or al, al                       ;
        jz .done                        ;
        mov ah, ASCII_CRTL_SO           ;
        int BIOS_INTRUPT_VIDEO          ;
        jmp .charLoop                   ;
    .done:                              ;
        ret                             ;

%endif ; __UTILS_INC_INCLUDED__
