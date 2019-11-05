all: main.o linkedlist.o library.o
	gcc -o program main.o linkedlist.o library.o

main.o: main.c header.h library.h
	gcc -c main.c

linkedlist.o: linkedlist.c header.h
	gcc -c linkedlist.c

libray.0: library.c library.h

run:
	./program

clean:
	rm *.o
	rm *~

memcheck:
	valgrind --leak-check=yes ./program
