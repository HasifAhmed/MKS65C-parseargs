all: parse.o
	gcc parse.o
run:
	./a.out $(args)
parse.o: parse.c parse.h
	gcc -c parse.c parse.h
