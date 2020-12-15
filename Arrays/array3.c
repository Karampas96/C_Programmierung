#include <stdio.h>

int main()
{
	int i[5];
	double abc[2000];
	
	printf("%d\n", sizeof(i[0])); // 4 Bytes
	printf("%d\n", sizeof(i)); // 20 Bytes
	printf("%d\n", sizeof(abc[0])); // 8 Bytes
	printf("%d\n", sizeof(abc)); // 16'000 Bytes
	
	return 0;
} //main
