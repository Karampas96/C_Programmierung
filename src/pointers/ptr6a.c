/* ptr6a.c */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	// Deklaration
	int *ptr;
	int var, var2;
	
	// Initialisieren: ptr bekommt die Adresse von var.
	ptr =& var;
	
	// Dereferenzierung : var bekommt den Wert 100 zugewiesen.
	*ptr=100;
	
	// var2 mit demselben Wert wie var initialisieren
	var2 = *ptr;
	
	*ptr+=100;     // Dereferenzierung: var wird um 100 erhöht.
	
	(*ptr)++;      // Dereferenzierung: var hat jetzt den Wert 201.
	(*ptr)--;      // var hat wieder den Wert 200.
	
	ptr=&var2;     // ptr zeigt auf var2.
	
	printf("%d\n", *ptr);    // Gibt Wert von var2 aus.
	printf("%p\n", &ptr);    // Gibt Adresse von ptr aus.
	printf("%p\n", ptr);     // Gibt Adresse von var2 aus.
	
	return EXIT_SUCCESS;
}
