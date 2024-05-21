run_main: build ./build/fms
	./build/fms

./build/fms: ./build/fms.o ./build/main.o
	gcc ./build/fms.o ./build/main.o -o ./build/fms -lm

./build/fms.o: ./src/fms.c
	gcc -Wall -g -c ./src/fms.c -o ./build/fms.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir -p build

clean:
	rm -r build