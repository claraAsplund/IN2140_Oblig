#include <stdio.h>
#include <stdlib.h>

/*
 * Printer tall på binaerform
 *
 * void *n  - Adressen til tall-variabelen som skal printes
 * int size - Størrelsen til tall-variabelen
 */
void printbits(void *n, int size)
{
    char *num = (char *)n;
    int i, j;

    for (i = size - 1; i >= 0; i--)
    {
        for (j = 7; j >= 0; j--)
        {
            printf("%c", (num[i] & (1 << j)) ? '1' : '0');
        }
        printf(" ");
    }
    printf("\n");
}

void printchar(unsigned char c)
{
    printbits(&c, sizeof(char));
}

void print_execution(unsigned char a, unsigned char b, unsigned char c)
{
    printf("a: ");
    printchar(a);
    printf("b: ");
    printchar(b);
    printf("=  ");
    printchar(c);
}

int main(void)
{
    // HUSK! Unsigned kan aldri være negativ
    // bruk av << og >>
    char ch = 1 << 7; // 1 = 0b00000001
    short s = ch;
    int i = s;

    // printf("%d\n", s);
    // printf("%d\n", i);

    // printbits(&ch, sizeof(char));
    // printbits(&s, sizeof(short));
    // printbits(&i, sizeof(int));

    printf("\n\n");

    // bruk av |, &, ^, ~
    unsigned char a, b, c;

    a = 0b01101101;
    b = 0b10111001;
    c = ~a;

    print_execution(a, b, c);
    return EXIT_SUCCESS;
}