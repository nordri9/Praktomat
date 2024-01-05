run_main: build ./build/number_to_text
	./build/number_to_text

./build/number_to_text: ./build/number_to_text.o ./build/main.o
	gcc ./build/number_to_text.o ./build/main.o -o ./build/number_to_text


./build/number_to_text.o: ./src/number_to_text.c
	gcc -Wall -g -c ./src/number_to_text.c -o ./build/number_to_text.o

./build/main.o: ./src/main.c
	gcc -Wall -g -c ./src/main.c -o ./build/main.o

build: 
	mkdir build

clean:
	rm -r build
