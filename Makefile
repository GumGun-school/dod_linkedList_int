

all: 
	gcc src/lib.c -o obj/lib.o -c
	gcc -o TEST obj/lib.o src/test.c




