/*******************************************************************************
* Programm:   Schaltjahr Erkennung                                                                   
* Filename:   Schaltjahr.c
*			   									   
* Autor:      Reindl Dominik				   								   									   
* Version:    1.0				   			   								   									   
* Datum:      30.03.2017
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0   30.03.2017   D.R.   Programm schreiben     45min
*                                                         Totalzeit:  45min 						   									   
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung: 
* In diesem Programm kann eine Jahreszahl eingegebgen werden um herauszu-
* finden ob diese Jahr ein Schaltjahr ist.
* 
* Precondition:  -
*
* Postcondition: -
*
* Benötigte Libraries:
* - stdlib.h
* - stdio.h
*
* Copyright (c) 2017 by D.Reindl, CH-6341 Unteraegeri
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
  int Zahl;   // Einzulesendes Jahr furr die ueberpruefung
                                                     

  /* Intro --------------------- */
  puts("*** Schaltjahr Erkennung *** \n\n");

  /* Eingabe ------------------- */
  printf("Bitte geben Sie das gewuenschte Jahr ein: ");
  scanf("%d", &Zahl);
  
  //Berechnung
  if (Zahl % 4 == 0)
  {
    if (Zahl % 100 == 0)
    {
      if (Zahl % 400 == 0)
      {
       printf("\n\n\nDas Jahr %d ist ein Schaltjahr",
       Zahl);
      }
      else 
      {
       printf("\n\n\nDas Jahr %d ist kein Schaltjahr",
       Zahl);
      }
    }
    else 
    {
     printf("\n\n\nDas Jahr %d ist ein Schaltjahr",
     Zahl);
    }   
  }
  else 
  {
  printf("\n\n\nDas Jahr %d ist kein Schaltjahr",
  Zahl);
  }
  

  /* Ausgabe ------------------- */
       puts("\n\n");
     
  /* Nur waehrend der Entwicklungsphase, spaeter loeschen! */
  system ("PAUSE");
  return (0);
}
