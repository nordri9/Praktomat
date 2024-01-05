run_main: build ./build/fibonacci_numbers
	./build/fibonacci_numbers

./build/fibonacci_numbers: ./build/fibonacci_numbers.o ./build/main.o
	gcc ./build/fibonacci_numbers.o ./build/main.o -o ./build/fibonacci_numbers


./build/fibonacci_numbers.o: ./src/fibonacci_numbers.c
	gcc -Wall -g -c ./src/fibonacci_numbers.c -o ./build/fibonacci_numbers.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
