# Variables
SRC_DIR = src
BUILD_DIR = build
EXECUTABLE = main

# Source file
SRC_FILE = $(SRC_DIR)/main.c

# Object file
OBJ_FILE = $(BUILD_DIR)/main.o

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Target to build the program
all: $(BUILD_DIR)/$(EXECUTABLE)

# Rule to build the executable
$(BUILD_DIR)/$(EXECUTABLE): $(OBJ_FILE)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Rule to build the object file
$(OBJ_FILE): $(SRC_FILE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to run the program
run: all
	./$(BUILD_DIR)/$(EXECUTABLE)

# Rule to clean build files
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all run clean
