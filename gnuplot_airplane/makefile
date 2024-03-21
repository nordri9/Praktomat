run_main: build ./build/gnuplot_airplane
	./build/gnuplot_airplane

./build/gnuplot_airplane: ./build/gnuplot_airplane.o ./build/main.o ./build/gnuplotopen.o
	gcc ./build/gnuplot_airplane.o ./build/main.o ./build/gnuplotopen.o -o ./build/gnuplot_airplane -lm

./build/gnuplot_airplane.o: ./src/gnuplot_airplane.c
	gcc -Wall -g -c ./src/gnuplot_airplane.c -o ./build/gnuplot_airplane.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

./build/gnuplotopen.o: ./src/gnuplotopen.c
	gcc -Wall -g -c ./src/gnuplotopen.c -o ./build/gnuplotopen.o

build: 
	mkdir -p build

clean:
	rm -r build
