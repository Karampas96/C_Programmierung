#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/* Array mit 5 int-Elementen */
	int i[5]; 
	
	/* Wertzuweisungen des Arrays */
	i[0] = 5;
	i[1] = 100;
	i[2] = 66;
	i[3] = 77;
	i[4] = 1500;
	
	//i[5] = 20;
	
	/* Ausgabe der einzelnen Array-Elemente */
	printf("Array-Element i[0]=%d\n", i[0]);
	printf("Array-Element i[1]=%d\n", i[1]);
	printf("Array-Element i[2]=%d\n", i[2]);
	printf("Array-Element i[3]=%d\n", i[3]);
	printf("Array-Element i[4]=%d\n", i[4]);
	
	//printf("Array-Element i[5]=%d\n", i[5]);
	//printf("Array-Element i[6]=%d\n", i[6]);
	
	return EXIT_SUCCESS;
}
