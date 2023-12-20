.PHONY: all run clean
CC = gcc
all: start
clean: 
	rm -rf start *.o
run: start
	./start
main.o: main.c
	$(CC) -c main.c
func2.o: func2.c
	$(CC) -c func2.c
func8.o: func8.c
	$(CC) -c func8.c
func16.o: func16.c
	$(CC) -c func16.c
start: main.o func2.o func8.o func16.o
	$(CC) main.o func2.o func8.o func16.o -o start -lm

