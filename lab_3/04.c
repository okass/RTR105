#include<stdio.h>

int fun()
{
	char x = 32 + 15;
	char delta = 7;
	x = x + delta;
	return x;
}

int main()
{
	char x = 32 + 15;
	printf("Pirms, %c \n", x);
	// %c parvers x vertibu ascii simbolaa
	//tiek printets "/"

	fun();
	printf("Pec 1 reizes, %c \n", x);
	// %c parvers x vertibu ascii simbolaa

	fun();
	printf("Pec 2 reizes, %c \n", x);
	// %c parvers x vertibu ascii simbolaa

	/*
	atskiriba no 03.c ir ta, ka x vertiba nav globala,
	bet atrodas tikai main funkcijas scope
	lai panaktu 03.c effektu butu jasauc funkcija fun()
	ar argumentu x un jaizstaj x funkcijaa main() ar
	atgriezto vertibu
	*/ 
	return 0;
}
