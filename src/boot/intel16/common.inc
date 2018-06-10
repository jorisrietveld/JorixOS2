;__________________________________________________________________________________________/ common.asm    
;   Author: Joris Rietveld  <jorisrietveld@gmail.com>
;   Created: 07-06-2018 18:29
;   
;   Description:
;   An collection of commonly used libraries. Most libraries define "Human Friendly" names
;   for hexadecimal addresses, function arguments, characters, etc.
;
%ifndef __COMM_INC_INCLUDED__
%define __COMM_INC_INCLUDED__

%include 'intel16/ascii.inc'
%include 'intel16/bios.inc'
%include 'intel16/types.inc'
%include 'intel16/ps2.inc'
%include 'intel16/jorix_debug.inc'

%endif ; __COMM_INC_INCLUDED__
