CC=gcc

CFLAGS = -Wall -g -O2

all: E7_ReverseInteger E121_BestTime2BuyShellStock

E7_ReverseInteger:
	$(CC) $(CFLAGS) -o E7_ReverseInteger.elf E7_ReverseInteger.c
E9_PalindromeNumber:
	$(CC) $(CFLAGS) -o E9_PalindromeNumber.elf E9_PalindromeNumber.c
E121_BestTime2BuyShellStock:
	$(CC) $(CFLAGS) -o E121_BestTime2BuyShellStock.elf E121_BestTime2BuyShellStock.c

clean:
	rm -rf *.o *.elf
