/* array_5.c */
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int meinezahlen[5] = {1, 2, 3};

    printf("%d\n", meinezahlen[0]);
    printf("%d\n", meinezahlen[3]); // filled with zero!

    return EXIT_SUCCESS;
}
