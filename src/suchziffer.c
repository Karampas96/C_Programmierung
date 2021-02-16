/*******************************************************************************
* Programm:   Suchziffer
* Filename:   Suchziffer.c
*
* Autor:      Ioannis Christodoulakis (IC)
* Version:    1.0
* Datum:      19.10.2020
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0     19.10.2020    IC    Erste Erstellung    30 min.         
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung:
* Dieses Programm bestimm die Anzahl der Ziffern, die einer bestimmten Such-
* ziffer entsprechen. Die einzugebende Zahl muss dem Datentyp Integer (int)
* entsprechen. Die Anzahl wird dem Benutzer am Ende des Programms mitgeteilt.
*
* Benötigte Libraries:
* - stdlib.h
* - stdio.h
*
* Copyright (c) 2020 by I.Christodoulakis, CH-6340 Baar
*******************************************************************************/

/***  Include Files ***********************************************************/
#include <stdio.h> /* Funktionsbibliothek: Standard Ein- Ausgabe */
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main() {
  
  // lokale Variablen
  int Ganzzahl;        // einzulesende Ganzzahl für Ziffersuche
  int Suchziffer;      // Ziffer, welche in der Variable Ganzzahl gesucht wird
  int Zifferzaehler;   // Anzahl der gefunden Suchziffer
  int Ziffer;          // Einzelziffer der Ganzzahl
  
  /* Intro --------------------- */
  puts("***SUCHZIFFER-PROGRAMM***\n\n");
  
  /* Eingabe ------------------- */
  printf("Bitte geben Sie die Ganzzahl als Integerwert ein. Ganzzahl: ");
  scanf("%d", &Ganzzahl);
  printf("\nBitte geben Sie die Suchziffer ein. Suchziffer: ");
  scanf("%d", &Suchziffer);

  /* Verarbeitung -------------- */
  Zifferzaehler = 0;
  do{
    Ziffer = Ganzzahl % 10;           // Einzelziffer herauslesen
    if(Suchziffer == Ziffer )         // Wenn <Ziffer> = <Suchziffer> dann
    {                                 // <Zifferzaehler> um 1 erhöhen
      Zifferzaehler++;
    }
    Ganzzahl /= 10;                   // <Ganzzahl> durch 10 dividieren
  }while(Ganzzahl > 0);              // Wiederhole solange <Ganzzahl> > 0
  
  /* Ausgabe -------------- */
  printf ("Die Suchziffer: %d wurde %d-mal gefunden.\n\n", 
  Suchziffer, Zifferzaehler);
  
  system ("PAUSE"); /* Nur während der Entwicklungsphase, später löschen! */
  return (0);
}//main
