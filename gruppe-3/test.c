
#include <stdio.h>

int main(void) {
    int arr = malloc(sizeof(int) * 10);
    if (arr == NULL) {
        printf("Malloc feilet\n");
        return 0;
    }

    arr[0] = 4493024853424;

    printf("%c\n", arr + 1);


    return 0;
}


-------
0x00 - 0x4000


-------




0x4000
0x4001
0x4002
0x4003
-------
