run_main: build ./build/prime_factors
	./build/prime_factors

./build/prime_factors: ./build/prime_factors.o ./build/main.o
	gcc ./build/prime_factors.o ./build/main.o -o ./build/prime_factors


./build/prime_factors.o: ./src/prime_factors.c
	gcc -Wall -g -c ./src/prime_factors.c -o ./build/prime_factors.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
