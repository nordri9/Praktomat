# Directories
SRC_DIR = src
BIN_DIR = bin

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files and target
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/jukebox.c
TARGET = $(BIN_DIR)/jukebox

# Create the bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Build the program
$(TARGET): $(BIN_DIR) $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_FILES)

# Run the program
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Clean the build
.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
