#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buff[255];
    int fd, wc;
    fd = open("hemmelig_melding.tekst", O_WRONLY | O_TRUNC);
    // fd = open("hemmelig_melding.tekst", O_RDONLY);
    if (fd == -1) {
        perror("Opening file");
        exit(-1);
    }

    char *mld = "Den andre katten hadde på sløyfe!";
    write(fd, mld, strlen(mld));
    if (wc == -1) {
        perror("Opening file");
        exit(-1);
    }



    // rc = read(fd, buff, 255);
    // if (rc == -1) {
    //     perror("Opening file");
    //     exit(-1);
    // }

    // printf("%s\n", buff);

    close(fd);
    return 0;
}
