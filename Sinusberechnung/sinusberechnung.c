#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define MAX 11

int main(void){
	
	float winkel;
	float winkelrad;
	float sin;
	char vorzeichen;
	float zaehler;
	float nenner;
	int count;
	
	printf("***Sinusberechnung***\n\n");
	
	printf("Winkel  in Grad eingeben: ");
	scanf("%f", &winkel);
	
	winkelrad = winkel * PI / 180;
	sin = winkelrad;
	vorzeichen = 1;
	zaehler = winkelrad;
	nenner = 1;
	count = 1;
	
	while(count < MAX){
		vorzeichen = vorzeichen * (-1);
		zaehler = zaehler * winkelrad * winkelrad;
		nenner = nenner * (count + 1)*(count + 2);
		count += 2;
		sin = sin + (vorzeichen * (zaehler / nenner));
	}
	
	printf("Ergebnis: %.2f", sin);
	
	return 0;
}
