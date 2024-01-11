run_main: build ./build/digits
	./build/digits

./build/digits: ./build/digits.o ./build/main.o
	gcc ./build/digits.o ./build/main.o -o ./build/digits


./build/digits.o: ./src/digits.c
	gcc -Wall -g -c ./src/digits.c -o ./build/digits.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
