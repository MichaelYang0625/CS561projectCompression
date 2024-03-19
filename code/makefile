CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = main

all: $(TARGET)

$(TARGET): main.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)