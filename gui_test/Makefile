#project name
NAME = guiTest
#include paths
INCLUDE = -Iinclude
#lib paths
LIBS = -L. -liup -Wl,-rpath='${ORIGIN}'

all:
	gcc -c -Wall -o main.o main.c
	gcc -o $(NAME) -Wall -L. $(LIBS) $(INCLUDE) main.o
