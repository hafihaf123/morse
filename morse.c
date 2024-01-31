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
	char* morseCode;
};

struct MorseMap map[] = {
	{'A', ".-"},
	{'B', "-..."},
	{'C', "-.-."},
	{'D', "-.."},
	{'E', "."},
	{'F', "..-."},
	{'G', "--."},
	{'H', "...."},
	{'I', ".."},
	{'J', ".---"},
	{'K', "-.-"},
	{'L', ".-.."},
	{'M', "--"},
	{'N', "-."},
	{'O', "---"},
	{'P', ".--."},
	{'Q', "--.-"},
	{'R', ".-."},
	{'S', "..."},
	{'T', "-"},
	{'U', "..-"},
	{'V', "...-"},
	{'W', ".--"},
	{'X', "-..-"},
	{'Y', "-.--"},
	{'Z', "--.."},
	{'0', ""},
	{'1', ".----"},
	{'2', "..---"},
	{'3', "...--"},
	{'4', "....-"},
	{'5', "....."},
	{'6', "-...."},
	{'7', "--..."},
	{'8', "---.."},
	{'9', "----."},
	{'0', "-----"},
	{'.', ".-.-.-"},
	{',', "--..--"},
	{'?', "..--.."},
	{'!', "-.-.--"},
	{':', "---..."},
	{'"', ".-..-."},
	{'=', "-...-"},
	{'/', "-..-."},
	{'(', "-.--."},
	{')', "-.--.-"},
	{'&', ".-..."},
	{';', "-.-.-."},
	{'+', ".-.-."},
	{'-', "-....-"},
	{'_', "..--.-"},
	{'$', "...-..-"},
	{'@', ".--.-."},
	{' ', "/"}
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

char* getStringMorse(char* ex) {
	char* res = strdup("");
	for (int i = 0; i < strlen(ex); i++) {
		char* morse = getMorse(ex[i]);
		res = realloc(res, strlen(res) + strlen(morse) + 2);
		strcat(res, morse);
		free(morse);
		strcat(res, " ");
	}
	return res;
}

char getSymbol(char* code) {
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
		if (strcmp(code, map[i].morseCode)) {
			return map[i].symbol;
		}
	}
	return 191;
}

char* decode(char* ex) {
	char* res = strdup("");
	char* token = strtok(ex, " ");

	while (token != NULL) {
		char c = getSymbol(token);
		strcat(res, &c);
		token = strtok(NULL, " ");
	}
	return res;
}

int main () {
	printf("enter the expression:\n");
	char text[100];
	fgets(text, sizeof(text), stdin);

	printf("to or from morse code? (t/f)\n");
	char toFrom;
	scanf("%c", &toFrom);
	
	char* res;
	if (toFrom == 't') {
		res = getStringMorse(text);
	} else if (toFrom == 'f') {
		res = decode(text);
	} else {
		res = "error, incorrect input";	
	}
	printf("%s\n", res);

	//free up memory logic
	free(res);

	return 0;
}
