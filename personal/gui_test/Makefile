#project name
NAME = bin/guiTest
#include paths
INCLUDE = -Iinclude
#lib paths
LIBS = -L./bin -liup -liupim -liupcd -liupimglib -lim -lim_process -lcd -lcdim -lm
#link so libs as being used from root of program
LDFLAGS = '-Wl,-rpath,$$ORIGIN/'

all: directories libs
	cd bin
	gcc -c -Wall -o main.o main.c
	gcc -o $(NAME) -Wall $(LIBS) $(LDFLAGS) $(INCLUDE) main.o

directories:
	mkdir -p bin

libs:
	tar -xf libs.tar.gz -C ./bin

clean:
	rm -rf ./bin
	rm *.o
