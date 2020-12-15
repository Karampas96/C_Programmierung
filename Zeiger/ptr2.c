/* ptr2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int abfrage;
   int Kapitel1 = 5;
   int Kapitel2 = 60;
   int Kapitel3 = 166;
   int Nachtrag = 233;
   
   int *Verzeichnis;   /* Zeiger */
   
   do {
      printf("INDEXREGISTER VOM BUCH\n");
      printf("*******************************\n\n");
      printf("-1- Kapitel 1\n");
      printf("-2- Kapitel 2\n");
      printf("-3- Kapitel 3\n");
      printf("-4- Nachtrag\n");
      printf("-5- Ende\n");
      printf("\n");
      printf("Auswahl : ");
      scanf("%d",&abfrage);
      printf("\nKapitel %d finden Sie auf ",abfrage);
      
      switch(abfrage) {
         case 1  :  Verzeichnis =& Kapitel1;
                    printf("Seite %d\n\n", *Verzeichnis);
                    break;
         case 2  :  Verzeichnis =& Kapitel2;
                    printf("Seite %d\n\n", *Verzeichnis);
                    break;
         case 3  :  Verzeichnis =& Kapitel3;
                    printf("Seite %d\n\n", *Verzeichnis);
                    break;
         case 4  :  Verzeichnis =& Nachtrag;
                    printf("Seite %d\n\n", *Verzeichnis);
                    break;
         default :  printf("Seite ???\n\n");
                    break;
      }
      
   } while(abfrage < 5);
   
   return EXIT_SUCCESS;
}
