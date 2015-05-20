C GB Header Reader
===========================

A C program that simply reads back important information from the header of a gameboy game binary.

## Requirements ##

You need a C compiler (e.g gcc)

## Usage ##

```
Glenn-Mac:src Glenn-Mac$ gcc -Wall romData.c headerDef.c -o romData
Glenn-Mac:src Glenn-Mac$ ./romData <romFile>
```

## Example Output ##

This is an example output running the program on my legal Pokemon Red backup:

```
Glenn-Mac:src Glenn-Mac$ ./romData poke.gb
*****************************************
*       C GB Rom Header Reader 0.15     *
*            Glenn McGuire 2015         *
*****************************************

ROM File Name:	poke.gb
ROM Name:	POKEMON RED
GBC Game?:	false
License Code:	0x3031
SGB Game?:	true
Catridge Type:	ROM+MBC3+RAM+BATT
ROM Size:	8Mbit = 1MByte = 64 banks
RAM Size:	256kBit = 32kB = 4 banks
Japanese Game?:	false
MaskRom Ver. #:	0x00
Compl. Check:	0x20
Checksum:	0x91E6

Glenn-Mac:src Glenn-Mac$
```

## To-Do ##

Add proper HashMap implementation for the static lookup data (Catridgetype, ROMsize, RAMsize)

## Copyright and License ##

This is free software, licensed under the MIT license.

## Thanks ##

Thanks to all the detailed resources out there covering this old but gold system!