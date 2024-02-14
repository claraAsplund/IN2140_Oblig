CFLAGS = -g -Wall -Wextra

BIN = med_buffring uten_buffring med_vs_uten

all: $(BIN)

med_buffring: med_buffring.c
	gcc med_buffring.c -o med_buffring


uten_buffring: uten_buffring.c
	gcc uten_buffring.c -o uten_buffring


med_vs_uten: med_vs_uten.c
	gcc med_vs_uten.c -o med_vs_uten

clean:
	rm -f $(BIN)