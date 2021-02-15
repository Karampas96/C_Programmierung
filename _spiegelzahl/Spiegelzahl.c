/*******************************************************************************
* Programm:   Spiegelzahl                                                                      
* Filename:   Spiegelzahl.c
*			   									   
* Autor:      Ioannis Christodoulakis		   								   									   
* Version:    1.0				   			   								   									   
* Datum:      04.09.2020
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0 04.09.20 Ioannis Christodoulakis Erste Erstellung 90 Min.
* 						   									   
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung: 
* Dieses Programm liest eine Ganzzahl (Integer) ein und berechnet daraus die 
  Spiegelzahl 
* 
* Precondition: 
  Ganzzahl darf keine 0 am Ende aufweisen. 
*
* Postcondition: -
*  
* Benötigte Libraries:
* - stdlib.h
* - stdio.h
*
* Copyright (c) 2020 by I.Christodoulakis, CH-6340 Baar
*******************************************************************************/

/***  Include Files ***********************************************************/
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */
#include <stdio.h>  /* Funktionsbibliothek: Standard Ein- Ausgabe */

/***  Globale Deklarationen und Definitionen **********************************/


/***  Funktions-Deklarationen *************************************************/
                                                                


/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(void) 
{
    
  // lokale Variablen
   int Ganzzahl; // Ganzzahl welche zu einer Spiegelzahl gewandelt werden muss.                                                  
   int Spiegelzahl; // Umgewandelte Ganzzahl(Resultat).
   int Ziffer; // Einzelziffer der Ganzzahl. 
   int c = 0;
   int i = 0;
  /* Intro --------------------- */
  printf("***SPIEGELZAHLBERECHNUNG***\n\n\n");

  /* Eingabe ------------------- */
  printf("Bitte geben Sie eine Ganzzahl des Datentypes Integer ein. Zahl = ");
  scanf("%d", &Ganzzahl);
  
  // Verarbeitung
  Spiegelzahl = 0;
  do
  {
    Ziffer = Ganzzahl % 10;
	if (Ziffer == 0 && i==0){
		c++;
	}
	else{
		i = 1;	
	}
    Ganzzahl = Ganzzahl / 10;
    Spiegelzahl = Spiegelzahl * 10 + Ziffer;
  } while (Ganzzahl > 0);
  
	printf("\n\nDie Spiegelzahl lautet:");
  
  	for(i=0; i<c; i++){
  		printf("0");
  	}
  
  /* Ausgabe ------------------- */
   printf("%d", Spiegelzahl);	
   printf("\n\n");

  system ("PAUSE"); /* Nur während der Entwicklungsphase, später löschen! */
  return (0);
}
