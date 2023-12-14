.PHONY: all clean run

all: nado

nado: main func2 func8 func16
	gcc main func2 func8 func16 -lm -o nado
main: main.c
	gcc main.c -c -lm -o main
func2: func2.c
	gcc func2.c -c -lm -o func2
func8: func8.c
	gcc func8.c -c -lm -o func8
func16: func16.c
	gcc func16.c -c -lm -o func16
run: nado
	./nado
clean:
	rm -rf main func2 func8 func16

