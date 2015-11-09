CC=gcc

CFLAGS = -Wall -g -O2

all: E7_ReverseInteger

E7_ReverseInteger:
	$(CC) $(CFLAGS) -o E7_ReverseInteger.elf E7_ReverseInteger.c

clean:
	rm -rf *.o *.elf
