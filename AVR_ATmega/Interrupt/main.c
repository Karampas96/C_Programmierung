/*******************************************************************************
Author      : Ioannis Christodoulakis (IC)
Project     : Interrupt
Version     : 1.0
Filename    : main.c
Created     : 26.10.2020
********************************************************************************
Target Hardware   : ELOB_V1722
Chip type         : ATmega2560
CPU-Clock         : 16.0000 MHz (ext.)
Program Memory    : 256 kByte
Internal RAM      : 8 kByte
EEPROM            : 4 kByte

********************************************************************************
Release Notes:
Version Date		Author	Comment/Reason for change    

*******************************************************************************/

/*------------------ Definitionen für die Delayfunktion-----------------------*/
#define F_CPU 16000000UL
/* CPU-Clock muss vor der Einbindung von delay.h definiert werden, da dieser
sonst bereits definiert wurde und darum nicht übernommen würde die
Wartefunktionen werden mittels _delay_ms(), oder _delay_us() aufgerufen    */


/******************************************************************************
 INCLUDES
*******************************************************************************/
#include <avr/io.h>
#include <avr/delay.h> // Enthält _delay_ms() und _delay_us()
#include <avr/interrupt.h> // Enthält Interrupt-Funktionen
#include <stdint.h>
//#include "stdtype.h"
//#include "elob_hw_init.h"
//#include "digital_io.h"  

/******************************************************************************
 DEFINES & Constant 
*******************************************************************************/

#define BIT0 0b00000001

// I/O's definieren
#define TASTER PINJ
#define SCHALTER PINC
#define LEDS PORTA

/******************************************************************************
 GLOBALS
*******************************************************************************/
uint8_t Zaehler = 0;
uint8_t Tasteralt;
uint8_t Tasterneu;

/******************************************************************************
 FUNCTIONS
*******************************************************************************/

//ISR PinChance
ISR(PCINT1_vect){
	Tasterneu = TASTER & BIT0;
	//positive Flanke erkennen
	if(Tasterneu && !Tasteralt){
		Zaehler++;
		}//if Funktion
	Tasteralt = Tasterneu;
}


int main(void){
	//Lokale Variablen

	
	// I/O-Konfigurationen
	DDRA = 0xFF;	// LEDs as Output
	DDRJ = 0x00;	// Taster as Input

	//PinChance Interrupt konfigurieren / aktivieren
	PCICR = 0b00000010; //interrupt aktivieren
	PCMSK1 = 0b00000010; //quelle definieren
	

	sei(); // set interrupt active	
	
	
    while(1){
		LEDS = Zaehler;
    }//while 1
}//main
