/*******************************************************************************
* Programm:   Ein erstes C-Programm
* Filename:   Histogram.c
*
* Autor:      Ioannis Christodoulakis
* Version:    1.0
* Datum:      30.08.2020
*
* Copyright (c) 2020 by I.Christodoulakis, CH-6340 Baar
*******************************************************************************/

/***  Include Files ***********************************************************/
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */
#include <stdio.h>  /* Funktionsbibliothek: Standard Ein- Ausgabe */

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(int argc, char* argv[], char* envp[]){
	FILE* stream;
	char *filename="Alice Adventure in Wonderland.txt";
	int count[256] = { 0 };
	int c; /* Ein Halter fuer jeden Buchstabe */
	int k;
	int char_count = 0;
	errno_t err;
	if(argc >= 2){
		filename = argv[1];
	}
	// Open File for read
	err = fopen_s(&stream, filename, "r");
	if(err == 0){
		printf("\nDie Datei '%s' wurde geoeffnet.\n\n", filename);
		if(stream){
			while((c = fgetc(stream))){
				if(c == EOF) break; // break if end of file
				count[c] += 1;
			}
			for(k = 0; k < 255; k++){
				if(count[k] > 0){
					printf("Der Buchstabe '%c' kommt %d-mal vor.\n", k, count[k]);
					char_count += count[k];
				}// count letter
			}//for all letters
			printf("\nAnzahl Zeichen: %d \n\n", char_count);
		}
		else{
			exit(0);
		}
	}//file opened
	else{
		printf("\nDie Datei '%s' wurde nicht richtig geoeffnet.\n\n", filename);
	}//file not opened
	// close stream if it is not NULL
	if(stream){
		err = fclose(stream);
		if(err == 0){
			printf("Die Datei '%s' wurde geschlossen.\n\n", filename);
		}//file closed
		else{
			printf("Die Datei '%s' wurde nicht richtig geschlossen.\n\n", filename);
		}//file not closed
	}//close stream
}//main
