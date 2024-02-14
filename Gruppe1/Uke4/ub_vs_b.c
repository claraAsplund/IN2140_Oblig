#include <fcntl.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"

int main(void) {

    fprintf(stdout, "Hello to");
    sleep(1);
    fprintf(stdout, " buffered\n");

    sleep(1);

    fprintf(stderr, "Hello to ");
    sleep(1);
    fprintf(stderr, " unbuffered\n");

    return 0;
}