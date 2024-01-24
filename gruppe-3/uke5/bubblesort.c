#include <stdio.h>
#include <time.h>

int main(void)
{
    int A[] = {4, 9, 3, 5, 8, 7, 2, 1, 6};
    int i = 0;
    int j = 0;

    // Bubble sort (in-place)
    clock_t start = clock();

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    clock_t end = clock();

    for (i = 0; i < 9; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nTime (CPU clock): %ld\n", (end - start));
}