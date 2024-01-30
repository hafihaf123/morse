/*
 * =====================================================================================
 *
 *       Filename:  morse.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/30/24 21:49:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (Michal Buchman), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct MorseMap {
	char symbol;
	char* morseCode
};

struct MorseMap map[] = {
	{'A', ".-"}
};

char* getMorse(char c) {
	for (int i=0; i < sizeof(map) / sizeof(map[0]); i++) {
		if (toupper(c) == map[i].symbol) {
			char* res = malloc(strlen(map[i].morseCode) + 1);
			strcpy(res, map[i].morseCode);
			return res;
		}
	}
	return strdup("");
}

int main () {
	printf("enter the expression:");
	char text[20];
	fgets(text, sizeof(text), stdin);
	printf("%s", text);

	return 0;
}
