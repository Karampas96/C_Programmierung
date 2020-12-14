#include <stdio.h>
#include <stdint.h>
#include <string.h>

void printString(char* str) {
	char c = *str;
	while (c) {
		printf("%c", c);
		str++;
		c = *str;
	}
}

// Beispiele für strukturen, funktionen und verwendung der Strukturen
typedef struct
{
	int32_t x;
	int32_t y;
}PointT;

typedef struct
{
	PointT TopLeft; // assume that TopLeft.X < BottomRight.X and TopLeft.Y < BottomRight.Y;
	PointT BottomRight;
}RectangleT;

uint32_t Area(const RectangleT* rect)
{
	uint32_t width = rect->BottomRight.x - rect->TopLeft.x;
	uint32_t height = rect->BottomRight.y - rect->TopLeft.y;
	return width * height;
}

typedef struct index {
	uint16_t seite;
	uint8_t titel[30];
	uint16_t address;
}lib;

struct ARTIKEL {
	uint16_t artikelnummer;
};

struct PERSONEN {
	uint16_t kundennummer;
}kunde;

void print(lib book)
{
	printf("Seite: %d\n", book.seite);
}


int main()
{
	uint8_t a = 128; // unsigned chat 0...255
	printf("Size of a*3: %d\n", sizeof(a * 3)); // -> 4 Byte
	printf("Value of a*3: %d\n", a * 3); // Value -> 384

	uint16_t x = 256;
	uint8_t y = x; // Wertebereich: 0...255 
	printf("Value of x: %d\n", x);
	printf("Value of y: %d\n", y); // 256 -> 0

	uint8_t z = 128;
	printf("Value of z: %d\n", z*2);

	uint8_t j = 0;
	printf("Value of j: %d\n", j-1);

	char str[] = "hallo world\n";
	printString(&str[0]);
	printString(str); // gleich

	uint8_t k = 100;
	uint8_t* p = &k;

	printf("Value of k: %i\n", k);
	printf("Address of k: %p\n", &k);
	printf("Value of p: %i\n", p);
	printf("Address of p: %p\n", &p);
	printf("Value of *p: %i\n", *p);

	lib points;
	points.seite = 20;
	strcpy_s(points.titel, sizeof points.titel , "C-Programmieren");
	print(points);
	//printf("Seite: %d\n", points.seite);

	printf("Titel: %s\n", points.titel);

	struct ARTIKEL ware1;
	struct ARTIKEL ware2 = {456};

	ware1.artikelnummer = 123;

	printf("Artikelnummer 1: %d\n", ware1.artikelnummer);
	printf("Artikelnummer 2: %d\n", ware2.artikelnummer);

	kunde.kundennummer = 789;

	printf("Kundennummer: %d\n", kunde.kundennummer);

	RectangleT R = {.TopLeft = {.x = 5, .y = 5},
					.BottomRight = {.x = 20, .y = 30}
				   };

	printf("Area: %d\n", Area(&R));

	lib point1 = {.address=10, .seite=23};

	printf("Address: %d, Seite: %d\n", point1.address, point1.seite);

	return 0;
}