#include<stdio.h>

int main(){
	char a = 1;
	int b = 14;
	long c = 22;

	char * pa = &a;
	int * pb = &b;
	long * pc = &c;

	printf("Address of a is %p and size is %ld\n", pa, sizeof(a));
	printf("Address of a is %p and size is %ld\n", pb, sizeof(b));
	printf("Address of a is %p and size is %ld\n", pc, sizeof(c));
}
