/*******************************************************************************
* Programm:   Potenzrechner
* Filename:   potenzrechner.c
*
* Autor:      Ioannis Christodoulakis (IC)
* Version:    1.0
* Datum:      26.10.2020
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0
*
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung: In diesem Programm können eine Basis und ein Exponent angegeben 
* werden. Das Resultat wird dann vom Programm ausgegeben.
*
* Precondition:  -
*
* Postcondition: -
*
* Benötigte Libraries:
*
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
 int calculatePotenz (int Basis, int Potenz);

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(void) {

  // lokale Variablen
  int Basiszahl = 0;
  int Potenzzahl = 0;
  int Resultat = 0;  

  /* Intro -------------------------------- */
  printf("*** Powerfunction *** \n\n");

  /* Eingabe ------------------------------ */
  printf("\n Geben Sie den Exponent als integer Wert an: ");
  scanf("%d", Potenzzahl);
  printf("Geben Sie die Basiszahl als integer Wert an: ");
  scanf("%d", Basiszahl);

  /* Verarbeitung und Ausgabe ------------- */
  Resultat = calculatePotenz(Basiszahl, Potenzzahl);

  /* Ausgabe ------------------------------ */
  printf("Das Resultat beträgt: %d \n", Resultat);   
  
  system ("PAUSE"); /* Nur während der Entwicklungsphase, später löschen! */
  return (0);
}
