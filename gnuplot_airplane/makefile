run_main: build ./build/gnuplot_airplane
	./build/gnuplot_airplane

./build/gnuplot_airplane: ./build/gnuplot_airplane.o ./build/main.o
	gcc ./build/gnuplot_airplane.o ./build/main.o -o ./build/gnuplot_airplane


./build/gnuplot_airplane.o: ./src/gnuplot_airplane.c
	gcc -Wall -g -c ./src/gnuplot_airplane.c -o ./build/gnuplot_airplane.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
