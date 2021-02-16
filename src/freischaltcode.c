/*******************************************************************************
* Programm:   Freischaltcode                                                                      
* Filename:   Freischaltcode.c
*			   									   
* Autor:      Ioannis Christodoulakis		   								   									   
* Version:    1.0				   			   								   									   
* Datum:      09.01.2021
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0 09.01.21 Ioannis Christodoulakis Erste Erstellung 90 Min.
* 						   									   
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung: 
* Dieses Programm liest eine positive 9-stellige Ganzzahl ein und ueberprueft
  auf Korrektheit des Freischaltcodes. Um die Korrektheit des Freischaltcodes
  zu ueberpruefen, wird ein sogenannter Pruefwert aus dem Freischaltcode 
  berechnet. Wenn der Pruefwert mit der Prueffziffer identisch ist, so wird
  dies dem Benutzer mitgeteilt ("Correct unlock code"). In der Realitaet
  wuerde jetzt der Installationsprozess beginnen.
* 
* Precondition: Die 9-stellige Nummer ist positiv!
*
* Postcondition: -
*  
* Benoetigte Libraries:
* - stdlib.h
* - stdio.h
*
* Copyright (c) 2020 by I.Christodoulakis, CH-6340 Baar
*******************************************************************************/

/***  Include Files ***********************************************************/
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */
#include <stdio.h>  /* Funktionsbibliothek: Standard Ein- Ausgabe */
//#include <assert.h>

/***  Globale Deklarationen und Definitionen **********************************/
#define MAX_TRIES 3

/***  Funktions-Deklarationen *************************************************/
unsigned char Check(unsigned int *pFreischaltcode);

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main(void)
{
	// lokale Variablen
	unsigned int freischaltcode; // einzulesender freischaltcode
	unsigned char result;
	unsigned char attempt = 0;

	/* Intro --------------------- */
	printf("*** Program for checking the unlock code ***\n\n");
	do
	{
		/* Eingabe ------------------- */
		printf("\nPlease enter the unlock code.\n");
		printf("Code = ");
		scanf("%d", &freischaltcode);
	  	result = Check(&freischaltcode);
	  	attempt = attempt + 1;
	  	// printf("attempts: %d, result: %d\n", attempt, result);
	}while(result != 0 && attempt < MAX_TRIES);
	/* Ausgabe ------------------- */
	if (result == 1){
		printf("\nUnlock code incorrect\n\n");
	}
	else
	{
		printf("\nCorrect unlock code\n\n");
	}
	/* Nur waehrend der Entwicklungsphase, spaeter loeschen! */
	system ("PAUSE");
  	return 0;
}


unsigned char Check(unsigned int *pFreischaltcode)
{
	//unsigned int code = 10; // 000311225
	unsigned int code = 81; // 122121121
	unsigned int pruefwertprodukt = 1;
	// remove the last digit
  	*pFreischaltcode /= 10;
	unsigned int r_digits = *pFreischaltcode % 10000;
  	// assign the first 4 digits in l_digits
  	unsigned int l_digits = *pFreischaltcode / 10000;
  	
  	do
	{
		// calculate the pruewertprodukt
  		pruefwertprodukt *= (l_digits % 10 + r_digits % 10);
  		// remove the last digit of both variables
  		l_digits /= 10;
  		r_digits /= 10;
	}while(l_digits > 0 || r_digits > 0);
	// Check the Freischaltcode
	// return 0 if the pruefwertprodukt is identical to code
	// else return 1
	return (pruefwertprodukt == code) ? 0 : 1;
}
