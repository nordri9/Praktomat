run_main: build ./build/gnuplot_airplane
	./build/gnuplot_airplane

./build/main.o: ./src/main.c
	gcc -Wall -g -lm -c ./src/main.c -o ./build/main.o

./build/gnuplotopen.o: ./src/gnuplotopen.c
	gcc -Wall -g -c ./src/gnuplotopen.c -o ./build/gnuplotopen.o

build: 
	mkdir -p build

clean:
	rm -r build
