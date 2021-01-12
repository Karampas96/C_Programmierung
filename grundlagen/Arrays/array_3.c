/* array_3.c */
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int test[10];
    int i;

    /* !!Bereichsueberschreibung!! */ 
    /*
    for(i=0; i<=10; i++) 
    {
        test[i] = i;
    }
    */

    for(i=0; i<=10; i++){
        printf("%d, ", test[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}
