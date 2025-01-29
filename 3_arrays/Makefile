# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude
# Directories
BIN_DIR = bin
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
# Target executable
TARGET = $(BUILD_DIR)/program
# Source and object files
SRCS = $(BIN_DIR)/main.c $(SRC_DIR)/array_utilities.c $(SRC_DIR)/error_code_processing.c
OBJS = $(SRCS:.c=.o)

# Build the executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile source files into object files
%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean compiled files
clean:
	rm -rf $(BUILD_DIR) $(OBJS)

.PHONY: clean