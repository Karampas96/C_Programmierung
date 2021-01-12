/* array_4.c */
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int i[5];
    double abc[2000];

    printf("%d\n", sizeof(i[0])); // 4 Bytes
    printf("%d\n", sizeof(i)); // 20 Bytes
    printf("%d\n", sizeof(abc[0])); // 8 Bytes
    printf("%d\n", sizeof(abc)); // 16'000 Bytes

    return EXIT_SUCCESS;
}
