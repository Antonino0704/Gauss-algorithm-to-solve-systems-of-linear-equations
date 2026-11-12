CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -std=c11

all: main

source/gauss.o: source/gauss.c source/gauss.h
	$(CC) $(CFLAGS) -c source/gauss.c -o source/gauss.o

lib/libgauss.a: source/gauss.o
	$(AR) rcs lib/libgauss.a source/gauss.o

main: lib/libgauss.a
	$(CC) $(CFLAGS) test/main.c -L./lib/ -lgauss -o main

clean:
	rm -f source/gauss.o main

.PHONY: all clean