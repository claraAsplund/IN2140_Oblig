CC=gcc
CFLAGS= -std=gnu11 -Wall -Wextra -g

SRCS=test_linkedlist.c linkedlist.c
OBJS=$(SRCS:.c=.o)
BIN=test_linkedlist

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(BIN)

test:
	@echo "CC = $(CC)"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
	@echo "BIN = $(BIN)"

