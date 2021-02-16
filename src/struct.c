#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct index{
	int seite;
	char titel[30];
};

struct index1{
	int seite;
	char titel[30];
}test = {308, "Strukturen"};

int main(void){
	struct index lib;
	lib.seite = 23;
	strcpy(lib.titel, "C-Programmieren");
	printf("%d, %s\n", lib.seite, lib.titel);
	
	//test.seite = 3;
	//strcpy(test.titel, "Test");
	printf("%d, %s\n", test.seite, test.titel);
	return 0;
}
