# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I./src
LDFLAGS = -lm

# Source and build directories
SRC_DIR = ./src
BUILD_DIR = ./build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files (corresponding to source files)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Target executable
TARGET = $(BUILD_DIR)/program

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug the program with GDB
debug: $(TARGET)
	gdb -ex "set environment LD_LIBRARY_PATH=$(BUILD_DIR)" --args $(TARGET)

# Phony targets
.PHONY: all clean run debug
