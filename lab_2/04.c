
#include<stdio.h>

float pi()
{
	return 3.14;
}

int main()
{
	int R = 123;
	float L = 2 * pi() * R;
	printf("Rinka radiuss: %d\nRinka linijas garums: %f m\n", R, L);
	return 0;
}
