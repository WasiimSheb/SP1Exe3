CC=gcc
AR=ar
CFLAGS= -Wall

all: StrList 

StrList: main.o StrList.o
	$(CC) $(CFLAGS) main.o StrList.o -o StrList

main.o: main.c
	$(CC) -c main.c

StrList.o: StrList.c StrList.h
	$(CC) -c StrList.c	

.PHONY: clean all

clean:
	rm -f *.o *.a *.so StrList
