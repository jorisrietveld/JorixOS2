<!-- 
  -- Author: Joris Rietveld <jorisrietveld@gmail.com>   
  -- Date: 08-06-2018 02:15    
  -- Licence: GPLv3 - General Public Licence version 3
  -- 
  -- Description:
  --  
  -->
# Registers of the Intel 8086 Achritecture

## GPR General Purpose Registers
<table>
  <thead>
    <tr>
    <th colspan="4" align="center"> <strong>Register name</strong> </th>
    <th align="center"> <strong>Name</strong> </th>
    <th align="center"> <strong>Description</strong> </th>
    </tr>
    <tr>
    <th>64</th>
    <th>32</th>
    <th>16</th>
    <th>8</th>
    <th></th>
    <th></th>
    </tr>
  </thead>
  <tbody>
    <tr><td align="right">rax</td><td>eax</td><td>ax</td><td>al</td><td align="right">       Accumilator Register </td><td align="right">                                                     Used in arithmetic operations. </td></tr>
    <tr><td align="right">rcx</td><td>ecx</td><td>cx</td><td>cl</td><td align="right">           Counter Register </td><td align="right">                                       Used in shift/rotate instructions and loops. </td></tr>
    <tr><td align="right">rdx</td><td>edx</td><td>dx</td><td>dl</td><td align="right">              Data Register </td><td align="right">                                  Used in arithmetic operations and I/O operations. </td></tr>
    <tr><td align="right">rbx</td><td>ebx</td><td>bx</td><td>bl</td><td align="right">              Base Register </td><td align="right"> Used as a pointer to data (located in segment register DS, when in segmented mode). </td></tr>
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
    <tr><td align="right">rx</td><td>ex</td><td>x</td><td>sp</td><td align="right">     Stack Pointer Register </td><td align="right">                                                   Pointer to the top of the stack. </td></tr>
    <tr><td align="right">rx</td><td>ex</td><td>x</td><td>SB</td><td align="right"> Stack Base Pointer Regiser </td><td align="right">                                                  Pointer to the base of the stack. </td></tr>
    <tr><td align="right">rx</td><td>ex</td><td>x</td><td>SI</td><td align="right">      Source Index Register </td><td align="right">                                Used as a pointer to a source in stream operations. </td></tr>
    <tr><td align="right">rx</td><td>ex</td><td>x</td><td>DI</td><td align="right"> Destination Index Register </td><td align="right">                           Used as a pointer to a destination in stream operations. </td></tr>
  </tbody>
</table>
