#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#include "info_struct.h"

int serialize(struct info *info, int *length, char *buffer)
{
    if (info == NULL || buffer == NULL)
        return 1; // husk! 1 er det samme som true

    // vi caster til en int-peker og dereferencer den.
    *(int *)buffer = htonl(info->lengde_navn); // konverter til network byte order.

    buffer += sizeof(int);

    for (int i = 0; i < info->lengde_navn; i++)
    {
        buffer[i] = info->navn[i];
    }

    buffer += info->lengde_navn;

    *(int *)buffer = htonl(info->alder);
    
    // vi har skrevet lengde_navn, alder og et navn. Vi trenger dette for å si til fwrite hvor mange bytes vi skal skrive.
    *length = sizeof(int) * 2 + info->lengde_navn;

    return 0;
}

void save_to_file(int length, char *buffer)
{
    const char *filename = "data.bin";

    FILE *file = fopen(filename, "w");

    fwrite(buffer, length, sizeof(char), file);

    fclose(file);
}

int main(void)
{
    // stuct som vi vil serialisere
    struct info person;

    person.navn = "Chris";
    person.lengde_navn = strlen(person.navn);
    person.alder = 23;

    char buffer[128] = {0};
    int lengde = 0;

    if (!serialize(&person, &lengde, buffer))
    {
        save_to_file(lengde, buffer);
    }

    return 0;
}