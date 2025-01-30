CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
BIN_DIR = bin
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TARGET = $(BUILD_DIR)/program
SRCS = $(BIN_DIR)/main.c $(SRC_DIR)/array_utilities.c $(SRC_DIR)/error_code_processing.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(OBJS)

.PHONY: clean