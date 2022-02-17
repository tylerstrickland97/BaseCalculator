
CC = gcc
CFLAGS = -Wall -std=c99 -g

calc10: calc.o number10.o operation.o
	gcc -o calc10 calc.o number10.o operation.o
	
calc25: calc.o number25.o operation.o
	gcc -o calc25 calc.o number25.o operation.o

calc.o: calc.c number.h operation.h
	gcc -Wall -std=c99 -g -c calc.c
		
number25.o: number25.c number.h operation.h
	gcc -Wall -std=c99 -g -c number25.c

number10.o: number10.c number.h operation.h
	gcc -Wall -std=c99 -g -c number10.c
	
operation.o: operation.c operation.h
	gcc -Wall -std=c99 -g -c operation.c
	
clean:
	rm -f operation.o number10.o number25.o calc.o
	rm -f calc10 calc25
	rm -f output.txt