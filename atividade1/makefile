CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
BIN_DIR = bin
SRCS = interface.c leitura_arquivo.c main.c
OBJS = $(patsubst %.c,$(BIN_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/main

.PHONY: all clean run

all: $(BIN_DIR) $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(BIN_DIR)/*

