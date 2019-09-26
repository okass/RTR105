#include <stdio.h>

int main()
{
	char name[16];
	char name2[16];
	int age;
	printf("Enter your name: ");
	scanf("%s", name);
	//printf("\n");

	printf("Enter your second name: ");
	scanf("%s", name2);
	printf("\n%s", name);
	//printf("\n%s", name2);
	printf("\n");

	printf("Your name is %s!\n", &name);
	printf("Your other name is %s!\n", &name2);
	return 0;
}
