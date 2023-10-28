

all: 
	gcc src/lib.c -o  obj/lib.o -c -g -D DEBUG
	gcc -o TEST obj/lib.o src/test.c -g




