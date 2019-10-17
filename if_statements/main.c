#include<stdio.h>
#define FALSE 0
#define TRUE 1


void isBigger()
{
	int number1, number2;
	printf("Enter number 1:\n");
	scanf("%d", &number1);
	printf("Enter number 2:\n");
	scanf("%d", &number2);
	if (number1 > number2)
	{
		printf("Number 1 is bigger than number 2\n\n");
	}
	else
	{
		printf("Number 2 is bigger than number 1\n\n");
	}
}

void isPowerTwo()
{
	int input;
	int isPowerTwo = FALSE;
	printf("Enter number:");
	scanf("%d", &input);
	for (int i = 1; i < 8; i++)
	{
		if (input == 1 << i)
		{
			isPowerTwo = TRUE;
			break;
		}
	}
	
	if (isPowerTwo)
	{
		printf("Number \"%d\" is power of 2\n\n", input);
	}
	else
	{
		printf("Number \"%d\" isnt power of 2\n\n", input);
	}
}

void isEven()
{
	int input;
	printf("Enter number:");
	scanf("%d", &input);
	printf("\n");
	if (input & 1)
	{
		printf("Number \"%d\" is odd\n\n", input);
	}
	else
	{
		printf("Number \"%d\" is even\n\n", input);
	}
}

void printActions()
{
	printf("Actions:\n1 - isBigger \n2 - isPowerTwo \n3 - isEven \n255 - exit\n");
}

int main()
{
	int isAlive = TRUE;
	while (isAlive)
	{
		int input;
		printActions();
		printf("Enter action:");
		scanf("%d", &input);
		printf("\n");
		switch(input)
		{
			case 1:
			{
				isBigger();
				break;
			}
			case 2:
			{
				isPowerTwo();
				break;
			}
			case 3:
			{
				isEven();
				break;
			}
			case 255:
			{
				isAlive = FALSE;
				break;
			}
			default:
			{
				printActions();
			}
		}
	}
	return 0;
}

//
