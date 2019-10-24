#include<stdio.h>
#include<string.h>

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
		{
			printHelp();
		}
	}
	return 0;
}
