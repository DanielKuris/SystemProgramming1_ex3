CC = gcc
AR = ar
CFLAGS = -Wall -g

all: StrList

libStrList.a: StrList.o
	$(AR) rcs libStrList.a StrList.o

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

StrList: main.o libStrList.a
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c StrList.h
	$(CC) $(CFLAGS) -c main.c


.PHONY: clean all

clean:
	rm -f *.o *.a StrList