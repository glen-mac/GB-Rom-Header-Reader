C GB Header Reader
===========================

A C program that simply reads back important information from the header of a gameboy game binary.

## Requirements ##

You need a C compiler (e.g gcc)

## Usage ##

```
./romData <romFile>
```

## Example Output ##

This is an example output running the program on my legal Pokemon Red backup:

```
Glenn-Mac:Desktop Glenn-Mac$ ./romData poke.gb
*****************************************
*       C GB Rom Header Reader 0.1      *
*           Glenn McGuire 2015          *
*****************************************

ROM Name:	50
GBC Game?:	false
License Code:	01
SGB Game?:	true
Catridge Type:	ROM+MBC3+RAM+BATT
ROM Size:	8Mbit = 1MByte = 64 banks
RAM Size:	256kBit = 32kB = 4 banks
Japanese Game?:	false
MaskRom Ver. #:	0x0
Compl. Check:	0x20
Checksum:	0x91
Glenn-Mac:Desktop Glenn-Mac$
```

## To-Do ##

Program only prints 1 byte of the checksum, need to alter ‘hexString’ method to do so.

Add comments throughout code

## Copyright and License ##

This is free software, licensed under the MIT license.

## Thanks ##

Thanks to all the detailed resources out there covering this old but gold system!