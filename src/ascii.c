/*******************************************************************************
* Programm:                                                                      
* Filename:   .c
*			   									   
* Autor:      Ioannis Christodoulakis				   								   									   
* Version:    1.0				   			   								   									   
* Datum:      
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0
*                                                         Totalzeit:   						   									   
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung: 
*     
* 
* Precondition:  -
*
* Postcondition: -
*
* Ben�tigte Libraries:
* - stdlib.h
* - stdio.h
*
* Copyright (c) 2017 by D.Reindl, CH-6340 Baar
*******************************************************************************/

/***  Include Files ***********************************************************/
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */
#include <stdio.h>  /* Funktionsbibliothek: Standard Ein- Ausgabe */

/***  Globale Deklarationen und Definitionen **********************************/


/***  Funktions-Deklarationen *************************************************/
                                                                


/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(void) {
    
  // lokale Variablen
	int Zahl=0;
	char Zeichen;                                             

  /* Intro --------------------- */
	printf("Bitte geben sie eine Zahl ein: ");
	scanf("%d" ,&Zahl);

  /* Eingabe ------------------- */
	Zeichen = Zahl;				// Hier wird das ANCII Zeichen in eine eigene Variabel gespeichert.

  /* Ausgabe ------------------- */
    printf("\nDie Zahl %d entspricht den ASCII-Zeichen: %c" ,Zahl ,Zeichen);
  return (0);
}
