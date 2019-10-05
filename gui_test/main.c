#include<stdio.h>
#include<stdlib.h>
#include "include/iup/iup.h"

int main(int argc, char **argv)
{
	IupOpen(&argc, &argv);

	IupMessage("Hello world title", "Hello world text");

	IupClose();
	return 0;
}
