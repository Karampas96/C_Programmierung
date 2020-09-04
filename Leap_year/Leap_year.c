/*******************************************************************************
* Programm:
* Filename:   Leap_year.c
*
* Autor:      Ioannis Christodoulakis (IC)
* Version:    1.0
* Datum:
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0     04.09.2020    IC    Erste Erstellung    2 Std.         
* 1.1     04.09.2020    IC    Format ändern       10 Min.
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung:
* Entwickeln Sie ein Programm welches zu jedem eingegebenen Jahr mitteilt, ob 
* es sich um ein Schaltjahr handelt oder nicht.
*
* Benötigte Libraries:
* - stdlib.h
* - stdio.h
*
* Copyright (c) 2013 by I.Christodoulakis, CH-6340 Baar
*******************************************************************************/

/***  Include Files ***********************************************************/
#include <stdio.h> /* Funktionsbibliothek: Standard Ein- Ausgabe */
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main() {
  // lokale Variablen
  int year;
  /* Eingabe ------------------- */
  printf("Enter a year: ");
  scanf("%d", &year);

  /* Verarbeitung und Ausgabe-------------- */
  if (((year % 4 == 0) && (year % 100!= 0)) || (year % 400 == 0))
    printf("%d ist ein Schaltjahr.", year);
  else
    printf("%d ist kein Schaltjahr.", year);
  
  return (0);
}
