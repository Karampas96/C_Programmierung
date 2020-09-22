#include <stdio.h>

int main(){
int ZahlA = 3, ZahlB = 5;
int *PtrA = &ZahlA, *PtrB = &ZahlB, *PtrC = PtrA;

printf("Zahl A = %u, ZahlB = %u, *PtrA = %u, *PtrB = %u, *PtrC = %u \n", ZahlA, ZahlB, *giPtrA, *PtrB, *PtrC);
printf("Ausgabe 1 : %u \n", PtrA == &ZahlA);
printf("Ausgabe 2 : %u \n", * * & PtrA);
printf("Ausgabe 3 : %u \n", 7 * *PtrA / *PtrB + 7);
printf("Ausgabe 4 : %u \n", *((char *)PtrB + 1) );
printf("Ausgabe 5 : %u \n", *(PtrC = &ZahlB) *= *PtrA + 1 );
printf("ZahlA = %u, ZahlB = %u, *PtrA = %u, *PtrB = %u, *PtrC = %u \n", ZahlA, ZahlB, *PtrA, *PtrB, *PtrC );
}//main
