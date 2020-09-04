/*****************************************************************************
 FILE : Template.c

 VERSION  DATE	    PROGRAMMER	REMARKS
   1.0    24.12.03  Muster H.   Template erstellt
   1.1    6.7.2006  Master S.   Kommentare eingefuegt

 USED BY
    C-Kurs / Grundlagen

 BESCHREIBUNG
    Dies ist eine Vorlagendatei fuer einfache C-Programme

 COPYRIGHT (C) 2006  by H.U.Steck  CH-6343 Rotkreuz
*****************************************************************************/
/* IMPORT ---------------------- */
#include <stdio.h>
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */

/* KONSTANTEN ------------------ */

/* VARIABLEN (global) ---------- */

/* HAUPTPROGRAMM --------------- */
int main()
 {
  /* VARIABLEN (lokal) --------- */
  int Jahreszahl;
  int Schaltjahr;
  int Restzahl;
  
  /* Intro --------------------- */
  printf("***   SCHALTJAHR    ***\n\n\n");
  
  
  /* Eingabe -------------------*/
  Schaltjahr = 0;
  
  printf("Bitte geben sie eine Jahreszahl als Integerwert ein: ");
  scanf( "%d", &Jahreszahl);

  Restzahl = Jahreszahl % 4;

  
  if(Restzahl == 0)
  {
     Schaltjahr = 1;
  } else
  {
     Schaltjahr = 0;
  }

  Restzahl = Jahreszahl % 100;

  
  if(Restzahl == 0)
  {
     Schaltjahr = 0;
  } 

  Restzahl = Jahreszahl % 400;

  
  if(Restzahl == 0)
  {
     Schaltjahr = 1;
  } 
 
  if(Restzahl = 1)
  {
     printf("\n\nDas Jahr %d ist ein Schaltjahr\n\n" ,Jahreszahl);
  } 
  else
  {
     printf("\n\nDas Jahr %d ist kein Schaltjahr\n\n" ,Jahreszahl);
  }
  
  /* Nur waehrend der Entwicklungsphase, spaeter loeschen! */
  system ("PAUSE");
  
  return 0;
 } /* ------------------------------------------------------------------------*/

/* Bildschirmdialog

*/

