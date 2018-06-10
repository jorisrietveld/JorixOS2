;__________________________________________________________________________________________/ jorix_debug.asm    
;   Author: Joris Rietveld  <jorisrietveld@gmail.com>
;   Created: 07-06-2018 18:25
;   
;   Description:
;   This are some functions and constants for printing debug messages.
%ifdef JORIX_DEBUG_ENABLE
%ifndef __JORIX_DEBUG_INC_INCLUDED__
%define __JORIX_DEBUG_INC_INCLUDED__

%include 'intel16/common.inc'

JX_DBG_TYPE db '[debug] in file', ASCII_CRTL_NULL
JX_NAME_LINE db ' on line: ', ASCII_CRTL_NULL
JX_LINE_MESG db ' Message: ', ASCII_CRTL_NULL

%macro debug_print 4
    print_16 JX_DBG_TYPE
    print_16 %2                         ; Print the filename.
    print_16 JX_NAME_LINE               ; Print an separator between the file name and line number.
    print_16 %3                         ; Print the line number.
    print_16 JX_LINE_MESG               ; Print separator between the line number and de message.
    print_16 %4                         ; Print the error message.

%endmacro

%endif ; __JORIX_DEBUG_INC_INCLUDED__
%endif ; JORIX_DEBUG_ENABLE
