run_main: build ./build/atmospheric_calculations
	./build/atmospheric_calculations

./build/atmospheric_calculations: ./build/atmospheric_calculations.o ./build/main.o
	gcc ./build/atmospheric_calculations.o ./build/main.o -o ./build/atmospheric_calculations -lm


./build/atmospheric_calculations.o: ./src/atmospheric_calculations.c
	gcc -Wall -g -c ./src/atmospheric_calculations.c -o ./build/atmospheric_calculations.o -lm

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
