run_main: build ./build/flight_distance
	./build/flight_distance

./build/flight_distance: ./build/flight_distance.o ./build/main.o
	gcc ./build/flight_distance.o ./build/main.o -o ./build/flight_distance


./build/flight_distance.o: ./src/flight_distance.c
	gcc -Wall -g -c ./src/flight_distance.c -o ./build/flight_distance.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
