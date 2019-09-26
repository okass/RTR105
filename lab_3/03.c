#include<stdio.h>

char x;

int fun()
{
	char delta = 9;
	x = x + delta;
	return x;
}

int main()
{
	x = 13 + 32;
	// %c parada x vertibu ascii formata
	// 45 ir "-"
	printf("Pirms, %c \n", x);

	fun();
	// %c parada x vertibu ascii formata
	// 54 ir "6"
	printf("Pec 1 reizes, %c \n", x);

	fun();
	// %c parada x vertibu ascii formata
	// 63 ir "?"
	printf("Pec 2 reizes, %c \n", x);
	return 0;
}
