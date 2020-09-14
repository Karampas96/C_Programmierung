/*
 * elob_hw_init.c
 *
 * Created: 02.08.2017 21:39:46
 *  Author: Ioannis Christodoulakis
 */ 


#include "elob_hw_init.h"



//hardware init
void elob_hw_init(void){
	
	
	//set the io registers
	DDRA = 0xFF; //port A is an output --> LEDs

	DDRC = 0x00; //port C as input --> switches

	DDRJ = 0x00; //port J as input --> pushbuttons
	
	// I/O-Konfigurationen
	//DDRA = 0xFF;	// PORTA als Ausgang definieren
	DDRB = 0xF7;    // PORTB0-2/4-7 als Ausgang und PORTB3 als Eingang definieren
	//DDRC = 0x00;	// PORTC als Eingang definieren
	DDRD = 0x88;    // PORTD0-2/4-6 als Ausgang und PORTD3/7 als Eingang definieren
	DDRE = 0x1A;    // PORTE1/3/4 als Ausgang und PORTE0/2/5-7 als Eingang definieren
	DDRF = 0x00;    // PORTF als Eingang definieren
	DDRG = 0xFF;    // PORTG als Ausgang definieren
	DDRH = 0xFF;	// PORTH als Ausgang definieren
	//DDRJ = 0x00;	// PORTJ als Eingang definieren
	DDRK = 0xFF;    // PORTK als Ausgang definieren
	DDRL = 0xFF;	// PORTL als Ausgang definieren
	
	
	
	
	// UART-Konfiguration
	/* Set baud rate */
	UBRR1 = 103; //  set baud rate to 9600 baud
	UCSR1B=0b10011000; // 0b11011000; Enable RX Complete Interrupt Enable / Enable TX Complete Interrupt Enable /  Receiver Enable / Transmitter Enable
	UCSR1C=0b00000110;
	
	
	
}//elob_hw_init

	







//EOF



