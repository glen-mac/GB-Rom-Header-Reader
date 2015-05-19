/*
 * The MIT License
 *
 * @Version 0.1
 * Copyright 2015 Glenn McGuire <glennmcguire9@gmail.com> <https://github.com/glen-mac>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <string.h>
#include "headerDef.h"

char *catridgeType[32] = {"ROM ONLY", "ROM+MBC1", "ROM+MBC1+RAM", "ROM+MBC1+RAM+BATT", NULL, "ROM+MBC2", "ROM+MBC2+BATTERY", NULL,
"ROM+RAM","ROM+RAM+BATTERY", NULL,  "ROM+MMM01", "ROM+MMM01+SRAM", "ROM+MMM01+SRAM+BATT", NULL, 
"ROM+MBC3+TIMER+BATT", "ROM+MBC3+TIMER+RAM+BATT", "ROM+MBC3", "ROM+MBC3+RAM", "ROM+MBC3+RAM+BATT", NULL, NULL, NULL, NULL, NULL,
"ROM+MBC5", "ROM+MBC5+RAM", "ROM+MBC5+RAM+BATT", "ROM+MBC5+RUMBLE", "ROM+MBC5+RUMBLE+SRAM","ROM+MBC5+RUMBLE+SRAM+BATT",
"Pocket Camera"};

char *romSize[7] = {"256Kbit = 32KByte = 2 banks", "512Kbit = 64KByte = 4 banks", "1Mbit = 128KByte = 8 banks",
"2Mbit = 256KByte = 16 banks", "4Mbit = 512KByte = 32 banks", "8Mbit = 1MByte = 64 banks",
"16Mbit = 2MByte = 128 banks"};

char *ramSize[5] = {"None", "16kBit = 2kB = 1 bank", "64kBit = 8kB = 1 bank", "256kBit = 32kB = 4 banks", "1MBit = 128kB = 16 banks"};

// //define ROM sizes
// romSize.put(0x0, "256Kbit = 32KByte = 2 banks");
// romSize.put(0x1, "512Kbit = 64KByte = 4 banks");
// romSize.put(0x2, "1Mbit = 128KByte = 8 banks");
// romSize.put(0x3, "2Mbit = 256KByte = 16 banks");
// romSize.put(0x4, "4Mbit = 512KByte = 32 banks");
// romSize.put(0x5, "8Mbit = 1MByte = 64 banks");
// romSize.put(0x6, "16Mbit = 2MByte = 128 banks");
// romSize.put(0x52, "9Mbit = 1.1MByte = 72 banks");
// romSize.put(0x54, "10Mbit = 1.2MByte = 80 banks");
// romSize.put(0x54, "12Mbit = 1.5MByte = 96 banks");

// //define RAM sizes
// ramSize.put(0x0, "None");
// ramSize.put(0x1, "16kBit = 2kB = 1 bank");
// ramSize.put(0x2, "64kBit = 8kB = 1 bank");
// ramSize.put(0x3, "256kBit = 32kB = 4 banks");
// ramSize.put(0x4, "1MBit = 128kB = 16 banks");

//memset(catridgeType, (int)NULL, 32 * sizeof(char *));
// catridgeType[0x00] = "ROM ONLY";
// catridgeType[0x01] = "ROM+MBC1";
// catridgeType[0x02] = "ROM+MBC1+RAM";
// catridgeType[0x03] = "ROM+MBC1+RAM+BATT";
// catridgeType[0x05] = "ROM+MBC2";
// catridgeType[0x06] = "ROM+MBC2+BATTERY";
// catridgeType[0x08] = "ROM+RAM";
// catridgeType[0x09] = "ROM+RAM+BATTERY";
// catridgeType[0x0B] = "ROM+MMM01";
// catridgeType[0x0C] = "ROM+MMM01+SRAM";
// catridgeType[0x0D] = "ROM+MMM01+SRAM+BATT";
// catridgeType[0x0F] = "ROM+MBC3+TIMER+BATT";
// catridgeType[0x10] = "ROM+MBC3+TIMER+RAM+BATT";
// catridgeType[0x11] = "ROM+MBC3";
// catridgeType[0x12] = "ROM+MBC3+RAM";
// catridgeType[0x13] = "ROM+MBC3+RAM+BATT";
// catridgeType[0x19] = "ROM+MBC5";
// catridgeType[0x1A] = "ROM+MBC5+RAM";
// catridgeType[0x1B] = "ROM+MBC5+RAM+BATT";
// catridgeType[0x1C] = "ROM+MBC5+RUMBLE";
// catridgeType[0x1D] = "ROM+MBC5+RUMBLE+SRAM";
// catridgeType[0x1E] = "ROM+MBC5+RUMBLE+SRAM+BATT";
// catridgeType[0x1F] = "Pocket Camera";
// catridgeType[0xFD] = "Bandai TAMA5";
// catridgeType[0xFE] = "Hudson HuC-3";
// catridgeType[0xFF] = "Hudson HuC-1";

char *getCatridgeType(byte indicator){
	return catridgeType[indicator];
}

char *getRomSize(byte indicator){
	return romSize[indicator];
}
char *getRamSize(byte indicator){
	return ramSize[indicator];
}