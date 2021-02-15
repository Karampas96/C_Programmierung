#include <stdio.h>

int main(void){
	/*Bei der Deklaration von String-Feldern sollte also auch 
	immer an das Ende-Zeichen gedacht werden, da dieses einen 
	zus�tzlichen Platz ben�tigt.*/
	char text[6] = "Hallo";
	printf("%s\n", text); // Hallo
	/*Wir haben die M�glichkeit Strings abzuschneiden, 
	indem wir das Ende-Zeichen manuell setzen.*/
	text[3] = "\0";
	printf("%s\n", text); // Hal
	return 0;
}
