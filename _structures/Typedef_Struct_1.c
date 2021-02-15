#include <stdio.h>

typedef struct _Coordinates_
{
	int x;
	int y;
} Coordinates;

void print(Coordinates input)
{
	printf("(%d/%d)\n", input.x, input.y);
}

void del(Coordinates *input)
{
	input->x = 0;
	input->y = 0;
}

int main()
{
	// Variante 1
	Coordinates point = {5,8};
	// Variante 2
	// Coordinates point;
	// point.x = 5;
	// point.y = 8;
	
	print(point);
	del(&point);
	print(point);
	return 0;
}
