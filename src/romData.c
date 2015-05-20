/*
 * The MIT License
 *
 * @Version 0.15
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

/** an array of the desired headerdata from the ROM binary */
byte headerData[28];

/** function prototype */
byte addrShift(int addr);
/** function prototype */
byte *subHead(int from, int to);
/** function prototype */
char *hexString(byte *hexArr);
/** function prototype */
char *hex2Ascii(byte *hexArr);

int main(int argc, char *argv[]){

	puts("*****************************************");
	puts("*       C GB Rom Header Reader 0.15     *");
	puts("*            Glenn McGuire 2015         *");
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

	fseek(fp, 308, SEEK_SET); //shift 308 bytes into the binary to get to the header
	fread(headerData, 1, 28, fp); //store 28 bytes of the header into our array
	fclose(fp); //close the file

	char *romName = hex2Ascii(subHead(0x134, 0x142));
	bool colourGame = (headerData[addrShift(0x143)] == 0x80) ? true : false;
	char *licenseCode = hexString(subHead(0x144, 0x145));
	bool sgbFunc = (headerData[addrShift(0x146)] == 0x03) ? true : false;
	char *catridgeType = getCatridgeType(headerData[addrShift(0x147)]);
	char *romSize = getRomSize(headerData[addrShift(0x148)]);
	char *ramSize = getRamSize(headerData[addrShift(0x149)]);
	bool japDestination = (headerData[addrShift(0x14A)] == 0) ? true : false;
	char *maskRom = hexString(subHead(0x14C, 0x14C));
	char *complementCheck = hexString(subHead(0x14D, 0x14D));
	char *checkSum = hexString(subHead(0x14E, 0x14F));

	printf("ROM File Name:\t%s\n", romFile);
	printf("ROM Name:\t%s\n", romName);
	printf("GBC Game?:\t%s\n", colourGame ? "true" : "false");
	printf("License Code:\t0x%s\n", licenseCode);
	printf("SGB Game?:\t%s\n", sgbFunc ? "true" : "false");
	printf("Catridge Type:\t%s\n", catridgeType);
	printf("ROM Size:\t%s\n", romSize);
	printf("RAM Size:\t%s\n", ramSize);
	printf("Japanese Game?:\t%s\n", japDestination ? "true" : "false");
	printf("MaskRom Ver. #:\t0x%s\n", maskRom);
	printf("Compl. Check:\t0x%s\n", complementCheck);
	printf("Checksum:\t0x%s\n", checkSum);
	puts("");

	return 0;
}

/** 
* Returns the header data index which has been shifted to account for the
* fact that we are using header data
*
* @param	addr	the hex ROM address we woud like to access
* @return	the header array index
*/
byte addrShift(int addr){
	return addr - 0x134;
}

/** 
* Returns a pointer to a 'byte' sub array of the headerData array using bounds, 
* assigning the first byte of the array to a hex representation of the number of 
* hex bytes following
*
* @param	from	the starting indexing location
* @param	to	the ending indexing location
* @return	a byte pointer to a sub array of the headerData array
*/
byte *subHead(int from, int to){
	byte numItems = (byte) (to-from+1);
	byte *subArr = (byte *) malloc((numItems + 1) * sizeof(byte));
	*subArr = numItems; //store number of bytes as the first byte in the array
	memcpy(subArr + 1, &headerData[addrShift(from)], numItems * sizeof(byte));
	return subArr;
}

/** 
* Returns a string pointer containing a string of the decimal-ASCII
* representation of a hex byte array
*
* @param	hex	an array of hex bytes with the first byte being the number
			of hex bytes following
* @return	a string pointer of an decimal-ASCII representation of 'hexArr'
*/
char *hex2Ascii(byte *hexArr){
	char *hexStr = (char *) malloc(*hexArr * sizeof(byte));
	sprintf(hexStr, "%s", hexArr + 1);
	return hexStr;
}

/** 
* Returns a string pointer containing a string of a hex byte array
*
* @param	hexArr	an array of hex bytes with the first byte being the number
			of hex bytes following	
* @return	a string pointer of an ASCII representation of 'hexArr'
*/
char *hexString(byte *hexArr){
	char *hexStr = (char *) malloc(*hexArr * sizeof(byte));
	int i = 0;
	do{
		sprintf(hexStr + 2*i, "%02X", *(hexArr + i + 1));
	} while(++i < *hexArr);
	return hexStr;
}

