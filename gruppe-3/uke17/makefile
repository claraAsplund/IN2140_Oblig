CFLAGS = -g -std=gnu11 -Wall -Wextra
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --malloc-fill=0x40 --free-fill=0x23
BIN = msn

msn: msn.c
	gcc $(CFLAGS) msn.c -o msn

