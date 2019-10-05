#include<stdio.h>
#define true 1
#define false 0

int main()
{
	int val = 10;
	int * ptr = &val;
	char var = 120;
	printf("shift left by 1 pos %d\n", 0x1 << 0x1 );
	printf("raw value %d\n", val);
	printf("pointer %d\n", ptr);
	printf("value from pointer %d\n", *ptr);
	printf("and 1 un 2 %d\nand 8 un 11 %d\n", 1 & 2, 8 & 11);
	printf("false 1 > 2 %d sizeof %d\n", 1 > 2, sizeof(1>2));
	printf("%d %d\n", true, false);
	printf("cast %d\n", (int)var);
	val += var;
	printf("val += var %d\n", val);
	return 0;
}
