run_main: build ./build/palindrome_numbers
	./build/palindrome_numbers

./build/palindrome_numbers: ./build/palindrome_numbers.o ./build/main.o
	gcc ./build/palindrome_numbers.o ./build/main.o -o ./build/palindrome_numbers


./build/palindrome_numbers.o: ./src/palindrome_numbers.c
	gcc -Wall -g -c ./src/palindrome_numbers.c -o ./build/palindrome_numbers.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
