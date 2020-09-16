/*******************************************************************************
* Programm:   Ein erstes C-Programm
* Filename:   Histogram.c
*
* Autor:      Ioannis Christodoulakis
* Version:    1.2
* Datum:      16.09.2020
*
* Copyright (c) 2020 by I.Christodoulakis, CH-6340 Baar
*******************************************************************************/

/***  Include Files ***********************************************************/
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */
#include <stdio.h>  /* Funktionsbibliothek: Standard Ein- Ausgabe */
#include <assert.h>

/***  Global Variables ********************************************************/
unsigned int count[256] = {0};

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(int argc, char* argv[], char* envp[]){
	FILE* stream = NULL;
	char *filename="Alice Adventure in Wonderland.txt";
	int c; /* a holder for each letter */
	int k;
	int max_letter = 0;
	int char_count = 0;
	errno_t err;
	if(argc >= 2){
		filename = argv[1];
	}
	// Open File for read
	err = fopen_s(&stream, filename, "r");
	if (err != 0){
		printf("\nDie Datei '%s' wurde nicht richtig geoeffnet.\n\n", filename);
		return 1;
	}
	assert(stream != NULL);
	while((c = fgetc(stream))){ //@RLA chave your condition => than you can get rid of the subsequent if!
		if(c == EOF) break; // break if end of file
		count[c]++;
		if (count[c] > count[max_letter]){
			max_letter = c;
		}
	}
	for(k = 0; k < 255; k++){
		if(count[k] > 0){
			printf("Der Buchstabe '%c' kommt %d-mal vor.\n", k, count[k]);
			char_count += count[k];
		}// count letter
	}//for all letters
	printf("\nAnzahl Zeichen: %d \n\n", char_count);
	printf("Max letter: '%c' -> %d\n", max_letter, count[max_letter]);
	// file closed
	fclose(filename);
}//main
