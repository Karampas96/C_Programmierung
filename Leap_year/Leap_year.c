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
int main() {
   int year;
   printf("Enter a year: ");
   scanf("%d", &year);

   // leap year if perfectly visible by 400
   if (year % 400 == 0) {
      printf("%d is a leap year.", year);
   }
   // not a leap year if visible by 100
   // but not divisible by 400
   else if (year % 100 == 0) {
      printf("%d is not a leap year.", year);
   }
   // leap year if not divisible by 100
   // but divisible by 4
   else if (year % 4 == 0) {
      printf("%d is a leap year.", year);
   }
   // all other years are not leap year
   else {
      printf("%d is not a leap year.", year);
   }

   return 0;
}
