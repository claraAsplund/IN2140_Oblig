#include <stdio.h>
#include <string.h>

    /*
    * Tar inn en char peker og oppretter en kopi av
    * strengen den peker på. Returnerer en peker
    * til kopien.
    *
    * Parametre: char *original     - den originale strengen
    * Returnerer: char *            - kopi av strengen.
    */
char *getCopy(char *original){
    char copy[strlen(original) + 1];
    for(int i = 0; i < strlen(original) + 1; i++){
        copy[i] = original[i];
    }
    return copy;
}

int main() {
    char *string = "Alle Cbraer vil ha kopier!";
    char *stringkopi = getCopy(string);
    return 0;
}
