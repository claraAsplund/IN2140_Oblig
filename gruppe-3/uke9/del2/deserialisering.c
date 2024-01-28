#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#include "info_struct.h"

int deserialize(struct info *info, char *buffer)
{
    if (info == NULL || buffer == NULL)
        return 1;

    info->lengde_navn = ntohl(*(int *)buffer); // tilbake til host byte order
    buffer += sizeof(int);

    // Kunne også ha brukt calloc her.
    info->navn = malloc((info->lengde_navn + 1) * sizeof(char));
    if (info->navn == NULL)
        return 1;

    for (int i = 0; i < info->lengde_navn; i++)
    {
        info->navn[i] = buffer[i];
    }
    info->navn[info->lengde_navn] = 0;

    buffer += info->lengde_navn;
    info->alder = ntohl(*(int *)buffer);

    return 0;
}

void read_from_file(int *length, char *buffer)
{
    const char *filename = "data.bin";
    FILE *file = fopen(filename, "r");

    // fseek med SEEK_END flytter posisjonen i filen til slutten av filen
    fseek(file, 0, SEEK_END);

    // ftell gir oss posisjonen i filen (dermed antall bytes i filen, gitt at
    // vi satt posisjonen til slutten)
    *length = ftell(file);

    // rewind setter posisjonen tilbake til starten av filen
    rewind(file);
    fread(buffer, sizeof(char), *length, file);

    fclose(file);
}

int main(void)
{
    struct info person = {0};

    char buffer[128] = {0};
    int lengde = 0;

    read_from_file(&lengde, buffer);

    if (!deserialize(&person, buffer))
    {
        printf("%s\n", person.navn);
        printf("%d\n", person.alder);

        free(person.navn);
    }

    return 0;
}
