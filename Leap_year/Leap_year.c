/*****************************************************************************
FILE : Leap_year.c

VERSION  DATE	    PROGRAMMER	REMARKS

USED BY 
  C-Kurs / Grundlagen

DESCRIPTION
  This is a template file for simple C programs.

COPYRIGHT (C) 2020  by I.Christodoulakis  CH-6340 Baar
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
  
  system ("PAUSE"); /* Nur während der Entwicklungsphase, später löschen! */
  
  return 0;
 } /* ------------------------------------------------------------------------*/

/* Bildschirmdialog

*/
