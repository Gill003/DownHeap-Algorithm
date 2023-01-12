CC = gcc
CFLAGS = -std=c99 -Wall
all:
	$(CC) $(CFLAGS)  A4Q1.c -o A4Q1 
clean:
	rm -f A4Q1