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

/**
* @RLA: Overall comment:
* You where very fast in finishing this assigment. 
* There are a couple of small things we will stil learn during this lecture with respect ot constants and
* string initialsation and manipulation.
* you do a good job in checking error cases. Try to be more stringent and use asserts in cases
* where things can be assumed to work under normal conditions.
* Deep if nestings are hard to follow. You could do with less!
*
* good work!
*/

/***  Include Files ***********************************************************/
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */
#include <stdio.h>  /* Funktionsbibliothek: Standard Ein- Ausgabe */


/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(int argc, char* argv[], char* envp[]){
	FILE* stream;
	char *filename="Alice Adventure in Wonderland.txt";
	int count[256] = { 0 }; // @RLA: I suggest that you declare this variable as a globla variable not a local one. Like this it will consume 1K stack space. Not a problem for a modern windows laptop. 
				// But on smaller systems it might be critical; if you want to keep it local to the function you just declare it as static!
				// gloabl int variables will be initialized to 0.
				// consider using types of stdint instead of int! the count will be positive in any case
	int c; /* Ein Halter fuer jeden Buchstabe */
	int k;
	int char_count = 0;
	errno_t err;
	if(argc >= 2){
		filename = argv[1];
	}
	// Open File for read
	err = fopen_s(&stream, filename, "r");
	//@RLA: as you can see your code gets quite deep nestings of if clauses. 
	// i would prefer if you just made your clean up in case of an error and return in the middel of the programm
	// overall it will be more readable
	if(err == 0){
		printf("\nDie Datei '%s' wurde geoeffnet.\n\n", filename);
		//@RLA: if stream is 0 at this point, something is wrong in the state of danemark
		// in this case you should abort your program. Use assert in this case! 
		// this avoids another if
		if(stream){
			while((c = fgetc(stream))){ //@RLA chave your condition => than you can get rid of the subsequent if!
				if(c == EOF) break; // break if end of file
				count[c] += 1;	    //@RLA: just put count[c]++;
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
		//@RLA: avoid these if statements; these cases are really critical and you 
		// should rather use asserts in case of such an error:
		if(err == 0){
			printf("Die Datei '%s' wurde geschlossen.\n\n", filename);
		}//file closed
		else{
			printf("Die Datei '%s' wurde nicht richtig geschlossen.\n\n", filename);
		}//file not closed
	}//close stream
}//main
