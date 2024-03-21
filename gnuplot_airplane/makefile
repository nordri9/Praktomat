run_main: build ./build/gnuplot_airplane
	./build/gnuplot_airplane

./build/main.o: ./src/main.c
	gcc -Wall -g -lm -c ./src/main.c -o ./build/main.o


build: 
	mkdir -p build

clean:
	rm -r build
