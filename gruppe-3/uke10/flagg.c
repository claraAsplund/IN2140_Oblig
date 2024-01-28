#include <stdio.h>
#include <stdlib.h>

/*
 * unsigned char
 * 6. bit = elektrisk (0b00100000)
 * 7. bit = eu_godkjent (0b01000000)
 */

#define IS_SET(flags, pos) (flags & (1 << pos))
#define PLUSS(a, b) a + b

struct bil
{
    int hjul;
    int alder;
    char *merke;

    unsigned char flags;
};


void set_flag(unsigned char *flags, int pos)
{
    *flags |= (1 << pos); // gjør bitwise operasjon OR og sett flags lik resultatet.
    //*flags = *flags | (1 << pos);
}

void unset_flag(unsigned char *flags, int pos)
{
    *flags &= ~(1 << pos);
}

int main(void)
{
    unsigned char bil = 0b01001101;

    set_flag(&bil, 5);
    set_flag(&bil, 6);
    unset_flag(&bil, 5);

    printf("2+3*5=%d\n", PLUSS(2, 3) * 5);

    if (is_electric(bil))
    {
        printf("Bilen er elektrisk\n");
    }
    else
    {
        printf("Bilen er ikke elektrisk\n");
    }

    // if (is_set(bil, 6))
    // {
    //     printf("Bilen er eu-godkjent\n");
    // }
    // else
    // {
    //     printf("Bilen er ikke eu-godkjent\n");
    // }

    return EXIT_SUCCESS;
}