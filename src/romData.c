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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "headerDef.h"

byte headerData[28];

byte numItems;
byte addrShift(int addr);
byte *subHead(int from, int to);
char *hexString(byte *hexArr);
char *hex2Ascii(byte *hexAr);

int main(int argc, char *argv[]){

	puts("*****************************************");
	puts("*       C GB Rom Header Reader 0.1      *");
	puts("*           Glenn McGuire 2015          *");
	puts("*****************************************\n");

	if (argc != 2)
	{
		fprintf(stderr, "Program Usage: ./<fileName> <romFileName.extension>\n");
		return 1;
	}

	char *romFile = argv[1];

	FILE *fp = fopen(romFile, "r");

	if (fp == NULL){
		fprintf(stderr, "ERROR: There were problem(s) opening file\n");
		return(1);
	}

	fseek(fp, 308, SEEK_SET); 
	fread(headerData, 1, 28, fp);
	fclose(fp);

	char *romName = hexString(subHead(0x134, 0x142));
	//for(int i=addrShift(0x134); i<=addrShift(0x142); i++)
		//romName[i] = headerData[i];
	bool colourGame = (headerData[addrShift(0x143)] == 0x80) ? true : false;
	char *licenseCode = hex2Ascii(subHead(0x144, 0x145));
	bool sgbFunc = (headerData[addrShift(0x146)] == 0x03) ? true : false;
	char *catridgeType = getCatridgeType(headerData[addrShift(0x147)]);
	char *romSize = getRomSize(headerData[addrShift(0x148)]);
	char *ramSize = getRamSize(headerData[addrShift(0x149)]);
	bool japDestination = (headerData[addrShift(0x14A)] == 0) ? true : false;
	char *maskRom = hexString(&headerData[addrShift(0x14C)]);
	char *complementCheck = hexString(&headerData[addrShift(0x14D)]);
	char *checkSum = hexString(subHead(0x14E, 0x14F));

	printf("ROM Name:\t%s\n", romName);
	printf("GBC Game?:\t%s\n", colourGame ? "true" : "false");
	printf("License Code:\t%s\n", licenseCode);
	printf("SGB Game?:\t%s\n", sgbFunc ? "true" : "false");
	printf("Catridge Type:\t%s\n", catridgeType);
	printf("ROM Size:\t%s\n", romSize);
	printf("RAM Size:\t%s\n", ramSize);
	printf("Japanese Game?:\t%s\n", japDestination ? "true" : "false");
	printf("MaskRom Ver. #:\t0x%s\n", maskRom);
	printf("Compl. Check:\t0x%s\n", complementCheck);
	printf("Checksum:\t0x%s\n", checkSum);

	free(licenseCode);

	return 0;
}

byte addrShift(int addr){
	return addr - 0x134;
}

byte *subHead(int from, int to){
	numItems = (to-from+1);
	byte *subArr = (byte *) malloc(numItems * sizeof(byte));
	memcpy(subArr, &headerData[addrShift(from)], numItems * sizeof(byte));
	return subArr;
}

char *hex2Ascii(byte *hexArr){
	char *hexStr = (char *) malloc(sizeof(*hexArr));
	sprintf(hexStr, "%s", hexArr);
	return hexStr;
}

char *hexString(byte *hexAr){
	char *hexStr = (char *) malloc(sizeof(*hexAr));
	int i = 0;
	//do{
	sprintf(hexStr + i, "%X", *(hexAr + i));
		//i++;
	//} while(i < numItems);
	return hexStr;
}

