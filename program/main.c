#include <stdio.h>

int main()
{
	int integrer_int = 16;
	short integrer_short = 16;
	char integrer_char = 16;
	long int integrer_long_int = 16;
	long long int integrer_long_long_int = 16;
	printf("%u\n", sizeof(integrer_char));
	printf("%u\n", sizeof(integrer_short));
	printf("%u\n", sizeof(integrer_int));
	printf("%u\n", sizeof(integrer_long_int));
	printf("%u\n", sizeof(integrer_long_long_int));
	printf("Hello world!\n");
	return 0;
}
