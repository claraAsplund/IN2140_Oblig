#include <stdio.h>

struct foo
{
    long a;  // 8 bytes
    int b;   // 4
    short c; // 2
    char d;  // 1
};

struct bar
{
    long a;
    int b;
    short c;
    char d;
} __attribute__((packed));

int main(void)
{
    struct foo test = {1L, 1, 1, 'a'};
    // struct bar test = {1L, 1, 1, 'a'};

    printf("struct foo: %zu\n", sizeof(struct foo));
    printf("struct bar: %zu\n", sizeof(struct bar));

    // valgrind liker ikke dette, vi leser uninitsialisert minne (paddingen)
    for (size_t i = 0; i < sizeof(struct foo); i++)
    {
        printf("0x%02hhx\n", ((char *)&test)[i]);
    }

    return 0;
}