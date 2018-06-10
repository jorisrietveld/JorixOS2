;__________________________________________________________________________________________/ Bios.asm    
;   Author: Joris Rietveld  <jorisrietveld@gmail.com>
;   Created: 06-01-2018 07:46
;   
;   Description:
;   This file defines easy to remember names for defining the BIOS interrupt services and arguments.
;
%ifndef __BIOS_INC_INCLUDED__
%define __BIOS_INC_INCLUDED__

; BIOS Interrupts.
%define BIOS_INTERRUPT_VIDEO     0x10   ; Video services, everything for displaying output on the screen.
%define BIOS_INTERRUPT_EQUIP_LST 0x11   ; Returns a list all all equipment.
%define BIOS_INTERRUPT_MEM_SIZE  0x12   ; Get the memory conventional size, quit hard to get in protected mode.
%define BIOS_INTERRUPT_DISK      0x13   ; Low level disk management, for controlling the hard disk, floppy or cd drives
%define BIOS_INTERRUPT_SERIAL    0x14   ; Serial Port Services, for serial communication between devices.
%define BIOS_INTERRUPT_MIC_SYS   0x15   ; Miscellaneous system services like: BIOS commands,
%define BIOS_INTERRUPT_KEYBOARD  0x16   ; Keyboard services for communication between the keyboard.
%define BIOS_INTERRUPT_PRINTER   0x17   ; Printer services for communication between printers.
%define BIOS_INTERRUPT_REBOOT    0x18   ; An (cold) reboot interrupt this will completely reset the computer.
%define BIOS_INTERRUPT_W_REBOOT  0x19   ; An warm reboot interrupt this will reset the computer but without wiping the RAM.

; Video Services Interrupt Arguments, INT 0x10.
%define I_VID_SET_VIDEO_MODE     0x00   ; Set Video Mode
%define I_VID_SET_CURSOR_SHAPE   0x01   ; Set Cursor Shape
%define I_VID_SET_CURSOR_POS     0x02   ; Set Cursor Position
%define I_VID_GET_CURSOR_POS     0x03   ; Get Cursor Position And Shape
%define I_VID_GET_PEN_POSITION   0x04   ; Get Light Pen Position
%define I_VID_SET_DISPLAY_PAGE   0x05   ; Set Display Page
%define I_VID_SCROLL_SCREEN_UP   0x06   ; Clear/Scroll Screen Up
%define I_VID_SCROLL_SCREEN_DOWN 0x07   ; Clear/Scroll Screen Down
%define I_VID_READ_CHAR_ATTR     0x08   ; Read Character and Attribute at Cursor
%define I_VID_WRITE_CHAR_ATTR    0x09   ; Write Character and Attribute at Cursor
%define I_VID_WRITE_CHAR_CURSOR  0x0A   ; Write Character at Cursor
%define I_VID_SET_BORDER_COLOR   0x0B   ; Set Border Color
%define I_VID_WRITE_GRAPH_PIXEL  0x0C   ; Write Graphics Pixel
%define I_VID_READ_GRAPH_PIXEL   0x0D   ; Read Graphics Pixel
%define I_VID_WRITE_CHAR_TTY     0x0E   ; Write Character in TTY Mode
%define I_VID_GET_VIDEO_MODE     0x0F   ; Get Video Mode

; Low level disk management, INT 13.
%define I_IO_RESET_DISK          0x00   ; Reset the disk drive.
%define I_IO_GET_STATUS          0x01   ; Check Drive Status.
%define I_IO_READ_SECTORS        0x02   ; Read Sectors.
%define I_IO_WRITE_SECTORS       0x03   ; Write Sectors.
%define I_IO_VERIFY_SECTORS      0x04   ; Verify Sectors.
%define I_IO_FORMAT_TRACK        0x05   ; Format Track.
%define I_IO_GET_DRIVE_PARMS     0x08   ; Get Drive Parameters.
%define I_IO_INIT_DRIVE_PARM     0x09   ; Init Fixed Drive Parameters.
%define I_IO_READ_LONG           0x0a   ; Reads a sector plus the ECC (Error correction data).
%define I_IO_WRITE_LONG          0x0b   ; Writes a sector allowing for the controller to calculate the ECC.
%define I_IO_SEEK_CYLINDER       0x0c   ; Moves the read/write head directly to an specific track.
%define I_IO_ALTERNATE_RESET     0x0d   ; Resets the hard disk system, but not the diskette controller.
%define I_IO_TEST DRIVE READY    0x10   ; Test if an drive is ready to precess a command.
%define I_IO_RECALIBRATE         0x11   ; Move head 0 to track 0.
%define I_IO_CONTROLLER DIAG     0x14   ; Let the hard disk controller perform a self test.
%define I_IO_GET_DISK_TYPE       0x15   ; Gets info about the type of disk.
%define I_IO_CHANGE_STATUS       0x16   ; Checks if the door of an disk device is opened (diskettes, cd-rom)
%define I_IO_SET_MEDIA_TYPE_OLD  0x17   ; Should be called before format operations, only for floppy drives < 720k.
%define I_IO_SET_MEDIA_TYPE      0x18   ; Set Floppy Drive Media Type
; Extended Disk Drive.
%define I_IO_EXT_NSTALL_CHECK    0x41   ; Extended Disk Drive (EDD) Installation Check
%define I_IO_EXT_READ_SECTORS    0x42   ; Extended Read Sectors
%define I_IO_EXT_WRITE_SECTORS   0x43   ; Extended Write Sectors
%define I_IO_EXT_VERIFY_SECTORS  0x44   ; Extended Verify Sectors
%define I_IO_LOCK_DRIVE          0x45   ; Lock/Unlock Drive
%define I_IO_UNLOCK_DRIVE        0x45   ; Eject Media
%define I_IO_EJECT_MEDIA         0x46   ; Extended Seek
%define I_IO_EXT_SEEK            0x47   ; Extended Get Drive Parameters
%define I_IO_EXT_GET_DRIVE_PARAM 0x48   ; Extended Get Media Change Status
%define I_IO_EXT_GET_MEDIA_STATUS 0x49  ; Extended Set Hardware Configuration
%define I_IO_EXT_SET_HARDWARE_CONFIG 0x4E; Extended Get Hardware Configuration

;  Serial Port Services, INT 14.
%define I_SP_SERIAL_PORT_INIT    0x00   ; Serial Port Initialization
%define I_SP_TRANSMIT CHARACTER  0x01   ; Transmit Character
%define I_SP_RECEIVE CHARACTER   0x02   ; Receive Character
%define I_SP_STATUS              0x03   ; Serial port Status

;  Miscellaneous system services
%define A20_ACTIVATE             0x2401 ; Enables the A20 gate with interrupt 15.
%define A20_STATUS               0x2402 ; Gets the current status of the A20 gate.
%define A20_SUPPORT              0x2403 ; Used to check if the CPU supports the BIOS int.

; Keyboard Services
%define I_K_READ CHAR            0x00 ; Read Character.
%define I_K_READ_INPUT_STATUS    0x01 ; Read Input Status.
%define I_K_READ_SHIFT_STATUS    0x02 ; Read Keyboard Shift Status.
%define I_K_STORE_KEYSTROKE      0x05 ; Store Keystroke in Keyboard Buffer.
%define I_K_EXT_READ_CHAR        0x10 ; Read Character Extended.
%define I_K_EXT_READ_INPUT_STATUS 0x11 ; Read Input Status Extended.
%define I_K_EXT_READ_SHIFT_STATUS 0x12 ; Read Input Status Extended.

%endif ;__BIOS_INC_INCLUDED__
