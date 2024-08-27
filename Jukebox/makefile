# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Target executable
TARGET = jukebox

# Source files directory
SRC_DIR = src

# Source files
SRC_FILES = $(SRC_DIR)/main.c

# Output directory for the binary
BIN_DIR = bin

# Create the output directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Build the target executable
$(BIN_DIR)/$(TARGET): $(SRC_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TARGET) $(SRC_FILES)

# Run the program
run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET)

# Clean up generated files
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: clean run
