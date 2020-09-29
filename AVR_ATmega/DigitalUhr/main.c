/*******************************************************************************
Firma        		: Siemens
Autoren        		: Plüss Thomas / Ioannis Christodoulakis
Projekt      		: Lötübung 7-Segment
Version      		: 1.0
Dateiname    		: LoetUebung 7-Segment_10Pin.c
Erstelldatum 		: 15.09.16
********************************************************************************
Chip type         	: ATmega2560
Clock frequency   	: 8.0000 MHz
Memory model      	: small
Internal RAM size 	: 8 kBytes
External RAM size 	: --
Data Stack size   	: --
********************************************************************************
Datum        Vers.        Kommentar / Änderungsgrund
15.09.16     1.0          Erstellt
*******************************************************************************/
// Verkabelung
/*
STK-600           7-Segment-Anzeige
-------           -----------------
PORTL Bit 0  ---  X(10-pol.) Pin 4
PORTL Bit 1  ---  X(10-pol.) Pin 5
PORTL Bit 2  ---  X(10-pol.) Pin 6
PORTL Bit 3  ---  X(10-pol.) Pin 7
PORTL Bit 4  ---  X(10-pol.) Pin 3
PORTL Bit 5  ---  X(10-pol.) Pin 2
PORTL Bit 6  ---  X(10-pol.) Pin 1
PORTL Bit 7  ---  X(10-pol.) Pin 8
X(PortL) Pin 9  ---  X(10-pol.) Pin 9
X(PortL) Pin 10  ---  X(10-pol.) Pin 10

PORTG Bit 0  ---  X(12-pol.) Pin 11
*/


// Definitionen für die Delayfunktion
#ifndef F_CPU
/* Definiere F_CPU, wenn F_CPU nicht bereits vorher definiert
(z.&nbsp;B. durch Übergabe als Parameter zum Compiler innerhalb
des Makefiles). Zusätzlich Ausgabe einer Warnung, die auf die
"nachträgliche" Definition hinweist */
#warning "F_CPU war noch nicht definiert, wird nun mit 3686400 definiert"
#define F_CPU 1000000UL     /* Quarz mit 8 Mhz */
#endif
/*------------------------------- Einbindungen -------------------------------*/
#include <avr/io.h>
#include <stdint.h>
#include <inttypes.h>
#include <util/delay.h>
/*---------------------------- Globale Variablen -----------------------------*/
/*--------------------- Konstanten & Definitionen ----------------------------*/
// Makros
#define SETBIT(Adr,Bit)         (Adr |= (1<<Bit))
#define CLEARBIT(Adr,Bit)       (Adr &= ~(1<<Bit))
#define CHECKBIT(Adr,Bit)       (Adr & (1<<Bit))
#define INVERTBIT(Adr,Bit)      (Adr ^= (1<<Bit))

// I/O's definieren
#define TASTER PINA
#define SCHALTER PINB

#define LED PORTC
#define SEGA PORTL
#define DOPP PORTG

/*------------------------------- Funktionen ---------------------------------*/

void Seg7_aus(volatile uint8_t *Segment)
{
	*Segment = 0x10;		// Zahl mit 0x10 verodern  (0bxxx1xxxx)
}

void Seg7(unsigned char Zahl, volatile uint8_t *Segment) {
	Zahl |= 0x30;		    // Zahl mit 0x30 verodern  (0bxx11xxxx)
	*Segment = Zahl;		// Zahl an 7-Segment ausgeben
//	_delay_us(500);
//	CLEARBIT (SEGA,5);
//	_delay_ms(1);
}

/*------------------------------- Hauptprogramm --------------------------------*/
int main(void) {

	DDRA = 0x00;            // PORTA ist Eingang (Taster)
	DDRC = 0xFF;            // PORTD ist Ausgang (LEDs)
	DDRL = 0xFF;			// PORTL ist Ausgang (7-Segment-Anzeige Platine)
	DDRG = 0xFF;			// PORTG ist Ausgang (Doppelpunkt)
	
	unsigned char zahl = 0;
	unsigned int i = 0;
	
	while (1) {
		while (TASTER == 0x01) {	//Zufallszahl 0..9 generieren während Tastendruck T0
			Seg7_aus(&SEGA);		//Display ausschalten
			SETBIT(SEGA,7);			//Dezimalpunkt einschalten
			SETBIT (DOPP,0);		//Doppelounkt einschalten
			++zahl;
			if (zahl == 10) zahl = 0;
		}
		if (SCHALTER == 0x01) {		//Durchzählen, wenn S0 ein
			for (i=0;i<10;i++)
			{
				LED = i;
				Seg7(i, &SEGA);
				_delay_ms(400);
			}
		}
		else {						//Ausgabe Zufallszahl (ohne Doppel- und Dezimalpunkt
			LED = zahl;
			CLEARBIT(DOPP,0);
			Seg7(zahl, &SEGA);	
		}
	}
}