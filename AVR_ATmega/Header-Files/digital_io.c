/*
 * digital_io.c
 *
 * Created: 02.08.2017 21:25:32
 *  Author: Marty
 */ 

#include "digital_io.h"




UINT8 get_input(void){
	
	UINT8 input_value = 0;
	
	//input_value = PINJ;
	input_value = PINC;
	
	return input_value;
	
}//get_input

