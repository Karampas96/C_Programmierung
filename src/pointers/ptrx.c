/*******************************************************************************
* Programm:                                                                      
* Filename:   .c
*			   									   
* Autor:      Reindl Dominik				   								   									   
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
* Benötigte Libraries:
* - stdlib.h
* - stdio.h
*
* Copyright (c) 2017 by D.Reindl, CH-6341 Unterägeri
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
  int Zahl1;
  char *ZeigerE;
  char *ZeigerA;
  char Zwischenspeicher;
  char Ausgabe
                                                     

  /* Intro --------------------- */
  printf("Bitte geben Sie eine Zahl an: ");
  scanf("%d", &Zahl1);


  /* Eingabe ------------------- */
  ZeigerE = &Zahl1;
  Zwischenspeicher = &Ausgabe;
  *(Zwischenspeicher) = *(ZeigerE+1);
  *(Zwischenspeicher+1) = *(ZeigerE);

  /* Ausgabe ------------------- */
  printf("%d" ,Zahl1);
     

  system ("PAUSE"); /* Nur während der Entwicklungsphase, später löschen! */
  return (0);
}

