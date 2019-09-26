#include<stdio.h>
#include<limits.h>

int main()
{
	long int a = 50000;
	long int b = 1000000;
	unsigned long long int c = a * b;

	printf("int datu tipa izmers ir: %d baiti\n", sizeof(int));
	printf("aprekina a un b reizinajumu: \n");
	printf("a = %d, b = %d \n", a, b);
	printf("c = a * b = %d * %d = %llu\n", a, b, c);

	return 0;
}
