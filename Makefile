CC=gcc
AR=ar
CFLAGS= -Wall

all: StrList 

StrList: Main.o StrList.o
	$(CC) $(CFLAGS) Main.o StrList.o -o StrList

Main.o: Main.c
	$(CC) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) -c StrList.c	

.PHONY: clean all

clean:
	rm -f *.o *.a *.so StrList
