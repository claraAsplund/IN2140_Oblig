CC = gcc
CFLAGS = -std=gnu11 -g -Wall -Wextra

TARGETS = bitops flagg masking

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS) data.bin