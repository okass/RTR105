#include<stdio.h>
#include<string.h>
#include<math.h>

int sort_big()
{
	int vars [3];

	//samērā nesmuks
	printf("Ievadiet trīs skaitļus:\n");
	scanf("%d", &vars[0]);
	scanf("%d", &vars[1]);
	scanf("%d", &vars[2]);
	int temp_vars [3];
	
	if (vars[0] > vars[1] && vars[0] > vars[2])
	{
		temp_vars[0] = vars[0];
		if (vars[1] > vars[2])
		{
			temp_vars[1] = vars[1];
			temp_vars[2] = vars[2];
		}else
		{
			temp_vars[1] = vars[2];
			temp_vars[2] = vars[1];
		}
	}
	if (vars[1] > vars[0] && vars[1] > vars[2])
	{
		temp_vars[0] = vars[1];
		if (vars[0] > vars[2])
		{
			temp_vars[1] = vars[0];
			temp_vars[2] = vars[2];
		}else
		{
			temp_vars[1] = vars[2];
			temp_vars[2] = vars[0];
		}
	}
	if (vars[2] > vars[0] && vars[2] > vars[1])
	{
		temp_vars[0] = vars[2];
		if (vars[0] > vars[1])
		{
			temp_vars[1] = vars[0];
			temp_vars[2] = vars[1];
		}else
		{
			temp_vars[1] = vars[1];
			temp_vars[2] = vars[0];
		}
	}
	
	printf("Sorted: %d;%d;%d\n", temp_vars[0], temp_vars[1], temp_vars[2]);
}

int sort_small()
{
	int vars [3];

	//samērā nesmuks
	printf("Ievadiet trīs skaitļus:\n");
	scanf("%d", &vars[0]);
	scanf("%d", &vars[1]);
	scanf("%d", &vars[2]);
	int temp_vars [3];
	
	if (vars[0] < vars[1] && vars[0] < vars[2])
	{
		temp_vars[0] = vars[0];
		if (vars[1] < vars[2])
		{
			temp_vars[1] = vars[1];
			temp_vars[2] = vars[2];
		}else
		{
			temp_vars[1] = vars[2];
			temp_vars[2] = vars[1];
		}
	}
	if (vars[1] < vars[0] && vars[1] < vars[2])
	{
		temp_vars[0] = vars[1];
		if (vars[0] < vars[2])
		{
			temp_vars[1] = vars[0];
			temp_vars[2] = vars[2];
		}else
		{
			temp_vars[1] = vars[2];
			temp_vars[2] = vars[0];
		}
	}
	if (vars[2] < vars[0] && vars[2] < vars[1])
	{
		temp_vars[0] = vars[2];
		if (vars[0] < vars[1])
		{
			temp_vars[1] = vars[0];
			temp_vars[2] = vars[1];
		}else
		{
			temp_vars[1] = vars[1];
			temp_vars[2] = vars[0];
		}
	}
	
	printf("Sorted: %d;%d;%d\n", temp_vars[0], temp_vars[1], temp_vars[2]);
}

int border()
{
	int i,N=50;
	for (i=1; i<=N; i++)
	{
		printf("(1+1/%d)^%d = %.5f\n", i, i,
				 pow(1 + 1/(float)i, i) );
	}
}

int factorial()
{
	int lastVal = 1;
	unsigned int lastValU = 1;
	int i = 1;
	
	// signed int
	while (1)
	{
		int fact = 1;
		for (int iter = 1; iter <= i; iter++)
		{
			fact = fact * iter;
			if (iter != i)
			{
				lastVal = fact;
			}
		}
		printf("%d %d %d\n", fact, i, lastVal);


		if (fact < lastVal)
		{
			printf("biggest factorial signed int: %d\n", i - 1);
			break;
		}

		i++;
	}

	lastVal = 0;
	// unsigned int
	while (1)
	{
		unsigned int fact = 1;
		for (unsigned int iter = 1; iter <= i; iter++)
		{
			fact = fact * iter;
			if (iter != i)
			{
				lastValU = fact;
			}
		}
		printf("%d %d %d\n", fact, i, lastValU);


		if (fact < lastValU)
		{
			printf("biggest factorial unsigned int: %d\n", i - 1);
			break;
		}

		i++;
	}
}

int printHelp()
{
	printf("Possible commands:\n"
		"exit - exits the program\n"
		"ascend - sort numbers in ascending order\n"
		"descend - sort numbers in descending order\n"
		"ascend_mod - sort modulus numbers in ascending order\n"
		"descend_mod - sort modulus numbers in descending order\n");
}

int main()
{
	char action[16];
	char isAlive = 1;
	while (isAlive)
	{
		printf("Enter action: ");
		scanf("%s", action);
		if (strcmp(action, "ascend") == 0)
		{
			sort_small();
		}else 
		if (strcmp(action, "descend") == 0)
		{
			sort_big();
		}else
		if (strcmp(action, "exit") == 0)
		{
			isAlive = 0;
		}else
		if (strcmp(action, "factorial") == 0)
		{
			factorial();
		}else
		if (strcmp(action, "border") == 0)
		{
			border();
		}else
		{
			printHelp();
		}
	}
	return 0;
}
