CC = gcc
CFLAGS = -Wall -Werror -g
SRC_DIR = ./src
OBJ_DIR = ./obj
TARGET = coconut_wings

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/island.c $(SRC_DIR)/node.c
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/island.o $(OBJ_DIR)/node.o

# Rule to create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to build the executable
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
