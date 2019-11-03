all: main.o linkedlist.o
	gcc -o program main.o linkedlist.o

main.o: main.c header.h
	gcc -c main.c

linkedlist.o: linkedlist.c header.h
	gcc -c linkedlist.c

run:
	./program

clean:
	rm *.o
	rm *~
