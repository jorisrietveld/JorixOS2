;__________________________________________________________________________________________/ types.asm    
;   Author: Joris Rietveld  <jorisrietveld@gmail.com>
;   Created: 07-06-2018 13:34
;   
;   Description:
;
[bits 16]

%ifndef __TYPE_INC_INCLUDED__
%define __TYPE_INC_INCLUDED__

%include 'intel16/ascii.inc'

%macro string 2
    %1 db %2, ASCII_CRTL_CR, ASCII_CRTL_LF, ASCII_CRTL_NULL
%endmacro

%endif ; __TYPE_INC_INCLUDED__
