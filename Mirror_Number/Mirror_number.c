/*******************************************************************************
* Programm: Spiegelzahl                                                                      
* Filename:   Spiegelzahl.c
*			   									   
* Autor:      Ioannis Christodoulakis		   								   									   
* Version:    1.0				   			   								   									   
* Datum:      16.3.2017
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0 16.3.17 Ioannis Christodoulakis Ganzes Programm erstellt 15 Min.
*                                                         Totalzeit: 15 Min.   						   									   
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
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
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
    Ganzzahl = Ganzzahl / 10;
    Spiegelzahl = Spiegelzahl * 10 + Ziffer;
  } while (Ganzzahl > 0);
  
  
  /* Ausgabe ------------------- */
   printf("\n\nDie Spiegelzahl lautet: %d", Spiegelzahl); 
   printf("\n\n");

  system ("PAUSE"); /* Nur während der Entwicklungsphase, später löschen! */
  return (0);
}
