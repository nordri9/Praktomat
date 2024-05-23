run_main: ./build/fms
	./build/fms

./build/fms: ./build/fms.o ./build/main.o ./build/data_structure.o ./build/fms_data.o
	gcc ./build/fms.o ./build/main.o ./build/data_structure.o ./build/fms_data.o -o ./build/fms -lm

./build/fms.o: ./src/fms.c
	gcc -Wall -g -c ./src/fms.c -o ./build/fms.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

./build/data_structure.o: ./src/data_structure.c
	gcc -Wall -g -c ./src/data_structure.c -o ./build/data_structure.o

./build/fms_data.o: ./src/fms_data.c
	gcc -Wall -g -c ./src/fms_data.c -o ./build/fms_data.o

build: 
	mkdir -p build

clean:
	rm -r build
