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
		size_t len = strlen(res) + strlen(morse) + 2;
		res = realloc(res, len);
		if (res == NULL) {
			fprintf(stderr, "memory reallocation failed\n");
			exit(EXIT_FAILURE);
		}
		strcat(res, morse);
		free(morse);
	}
	return res;
}

char getSymbol(char* code) {
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
		if (strcmp(code, map[i].morseCode) == 0) {
			return map[i].symbol;
		}
	}
	return '?';
}

char* decode(char* ex) {
	char* res = strdup("");
	char* token = strtok(ex, " ");

	while (token != NULL) {
		char c = getSymbol(token);
		strncat(res, &c, 1);
		token = strtok(NULL, " ");
	}
	return res;
}

int containsOnly(char* ex, char* tokens) {
	int bool = 0;
	for (int i = 0; i < strlen(ex); i++) {
		char c = ex[i];
		for (int ii = 0; ii < strlen(tokens); ii++) {
			if (tokens[ii] == c) {
				bool = 1;
				break;
			}
		}
		if (bool != 1) return bool;
	}
	return bool;
}

int main () {
	printf("enter the expression:\n");
	char text[100];
	fgets(text, sizeof(text), stdin);

	/*printf("to or from morse code? (t/f)\n");
	char toFrom;
	scanf("%c", &toFrom);*/
	
	char* res;
	if (containsOnly(text, ".-/")) {
		res = decode(text);
	} else {
		res = getStringMorse(text);	
	}
	printf("%s\n", res);

	//free up memory logic
	free(res);

	return 0;
}
