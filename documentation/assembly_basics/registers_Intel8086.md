<!-- 
  -- Author: Joris Rietveld <jorisrietveld@gmail.com>   
  -- Date: 08-06-2018 02:15    
  -- Licence: GPLv3 - General Public Licence version 3
  -- 
  -- Description:
  --  
  -->
# Registers of the Intel 8086 Achritecture

## The register build up
_This table shows the names of the registers and how they are build up. notice that the 16 bit register
is build up from 2 registers each 1 byte long. They are the registers with the H and L surfix_

<table>
    <tr>
        <th>64 bit</th>
        <th>32 bit</th>
        <th>16 bit high</th>
        <th>16 bit low</th>
    </tr>
    <tr>
        <td colspan="2"></td>
        <td align="center">{}H</td>
        <td align="center">{}L</td>
    </tr>
    <tr>
        <td colspan="2></td>
        <td colspan="2></td>
        <td colspan="2" align="center">{}X</td>
    </tr>
    <tr>
      <td></td>
      <td colspan="3" align="center">E{}X</td>
    </tr>
    <tr>
      <td colspan="4" align="center">R{}X</td>
    </tr>
    <tr>
        <td colspan="2"></td>
        <td align="center">`AH BH CH DH`</td>
        <td align="center">`AL BL CL DL`</td>
    </tr>
    <tr>
      <td align="center" colspan="2"></td>
      <td colspan="2" align="center">`AX BX CX DX`</td>
    </tr>
    <tr>
        <td align="center"></td>
        <td align="center" colspan="3">`EAX EBX ECX EDX`</td>
      </tr>
      <tr>
      <td align="center"colspan="4">`RAX RBX RCX RDX`</td>
    </tr>
</table>

## General Purpose Registers
<table>
  <thead>
    <tr>
    <th colspan="4" align="center"> <strong>Register name</strong> </th>
    <th rowspan="2" align="center"> <strong>Name</strong> </th>
    <th rowspan="2" align="center"> <strong>Description</strong> </th>
    </tr>
    <tr>
    <th>64</th>
    <th>32</th>
    <th>16</th>
    <th>8</th>
    </tr>
  </thead>
  <tbody>
    <tr><td align="right">rax</td><td>eax</td><td>ax</td><td>al</td><td align="right">       Accumilator Register </td><td align="right">                                                     Used in arithmetic operations. </td></tr>
    <tr><td align="right">rcx</td><td>ecx</td><td>cx</td><td>cl</td><td align="right">           Counter Register </td><td align="right">                                       Used in shift/rotate instructions and loops. </td></tr>
    <tr><td align="right">rdx</td><td>edx</td><td>dx</td><td>dl</td><td align="right">              Data Register </td><td align="right">                                  Used in arithmetic operations and I/O operations. </td></tr>
    <tr><td align="right">rbx</td><td>ebx</td><td>bx</td><td>bl</td><td align="right">              Base Register </td><td align="right"> Used as a pointer to data (located in segment register DS, when in segmented mode). </td></tr>
</table>

## Stack Registers
<table>
  <thead>
    <tr>
    <th colspan="4" align="center"> <strong>Register name</strong> </th>
    <th rowspan="2" align="center"> <strong>Name</strong> </th>
    <th rowspan="2" align="center"> <strong>Description</strong> </th>
    </tr>
    <tr>
    <th>64</th>
    <th>32</th>
    <th>16</th>
    <th>8</th>
    </tr>
  </thead>
  <tbody>
    <tr><td align="right">rsp</td><td>esp</td><td>sp</td><td>spl</td><td align="right"> Stack Pointer Register </td><td align="right">  Pointer to the top of the stack. </td></tr>
    <tr><td align="right">rbp</td><td>ebp</td><td>bp</td><td>bpl</td><td align="right"> Stack Base Pointer Regiser </td><td align="right"> Pointer to the base of the stack. </td></tr>
  </tbody>
</table>

## Pointer Registers
<table>
  <thead>
    <tr>
    <th colspan="4" align="center"> <strong>Register name</strong> </th>
    <th rowspan="2" align="center"> <strong>Name</strong> </th>
    <th rowspan="2" align="center"> <strong>Description</strong> </th>
    </tr>
    <tr>
    <th>64</th>
    <th>32</th>
    <th>16</th>
    <th>8</th>
    </tr>
  </thead>
  <tbody>
    <tr><td align="right">rsp</td><td>esp</td><td>si</td><td>sil</td><td align="right"> Source Index </td><td align="right">        Used as a pointer to a source in stream operations. </td></tr>
    <tr><td align="right">rdp</td><td>edp</td><td>di</td><td>dil</td><td align="right"> Destination Index </td><td align="right">   Used as a pointer to a destination in stream operations. </td></tr>
    <tr><td align="right">rip</td><td>eip</td><td>ip</td><td>ipl</td><td align="right"> Instruction Pointer </td><td align="right"> Used as a pointer to the next instruction to execute. </td></tr>
  </tbody>
</table>

## Segment Registers
<table>
  <thead>
    <tr>
    <th colspan="1" align="center"> <strong>Register name</strong> </th>
    <th align="center"> <strong>Name</strong> </th>
    <th align="center"> <strong>Description</strong> </th>
    </tr>
  </thead>
  <tbody>
    <tr><td align="right"> cs </td><td align="right"> Code Segment </td><td align="right"> </td></tr>
    <tr><td align="right"> ds </td><td align="right"> Data Segment </td><td align="right"> </td></tr>
    <tr><td align="right"> ss </td><td align="right"> Stack Segment </td><td align="right"> </td></tr>
    <tr><td align="right"> es </td><td align="right"> Extra Segment </td><td align="right"> </td></tr>
    <tr><td align="right"> fs </td><td align="right"> File Segment </td><td align="right"> </td></tr>
    <tr><td align="right"> gs </td><td align="right"> General Segment </td><td align="right"> </td></tr>
  </tbody>
</table>
