/*******************************************************************************
* Programm:   Summenberechnung
* Filename:   Summenberechnung.c
*
* Autor:      Ioannis Christodoulakis (IC)
* Version:    1.0
* Datum:      04.09.2020
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0   04.09.2020    IC    Erste Erstellung    30 Min.
*
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung: Dieses Programm berechnet die Summe zweier Ganzzzahlen, welche 
* durch den Benutzer einzugeben sind. Die Zahlen muessen dem Datentyp: Integer 
* entsprechen. Das Resultat wird dem Benutzer nach der Berechnung auf dem 
* Display mitgeteilt.
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


/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(void) {

  // lokale Variablen
  int Zahl1;
  int Zahl2;
  int Summe;

  /* Intro -------------------------------- */
  printf("Summenberechnungs-Programm\n\n");

  /* Eingabe ------------------------------ */
  printf("Bitte geben Sie die erste Integer-Ganzzahl ein: ");
  scanf ("%d", &Zahl1);
  printf("Bitte geben Sie die zweite Integer-Ganzzahl ein: ");
  scanf ("%d", &Zahl2);

  /* Verarbeitung und Ausgabe ------------- */
  Summe = Zahl1 + Zahl2;

  /* Ausgabe ------------------------------ */
  printf("Die Summe von %d und %d ist %d \n\n", Zahl1, Zahl2, Summe);
  
  return (0);
}
