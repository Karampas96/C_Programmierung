/* pointers_1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void){

	int x=5;
	int *p;
	
	printf("Der Wert von x ist %d \n", x);
	printf("Die Adresse von x ist %p \n", &x);
	printf("Der Wert von p ist %d \n", p);
	printf("Die Adresse von p ist %p \n", &p);
	
	p = &x;
	
	printf("Der Wert von p ist %p \n", p);
	printf("Der Wert von *p ist %d \n", *p);
	
	*p = 10;
	
	printf("Der Wert von x ist %d \n", x);
	
	return EXIT_SUCCESS;
}
