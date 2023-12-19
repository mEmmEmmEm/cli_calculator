.PHONY: all run clean
all: start
clean: 
	rm -rf start *.o
run: start
	./start
main.o: main.c
	gcc -c main.c
func2.o: func2.c
	gcc -c func2.c
func8.o: func8.c
	gcc -c func8.c
func16.o: func16.c
	gcc -c func16.c
start: main.o func2.o func8.o func16.o
	gcc main.o func2.o func8.o func16.o -o start
