#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int n)
{
    int i, least, pos, temp, j;
    for (i = 0; i < n; i++)
    {
        least = A[i];
        pos = i;

        for (j = i + 1; j < n; j++)
        {
            if (A[j] < least)
            {
                least = A[j];
                pos = j;
            }
        }

        if (i != pos)
        {
            temp = A[i];
            A[i] = A[pos];
            A[pos] = temp;
        }
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int i, n, A[100000];
    double diff;
    clock_t start, end;
    srand(time(NULL));
    printf("How much n? -> ");
    scanf("%d", &n);  // Removed the space after %d
    for (i = 0; i < n; i++)
        A[i] = rand();
    display(A, n);
    start = clock();
    selectionSort(A, n);
    end = clock();
    diff = (double)(end - start) / CLOCKS_PER_SEC;  // Use double for higher precision
    display(A, n);
    printf("Time = %.6f seconds\n", diff);
    return 0;
}
/*
best case = O(n)
Worst case = O(n2)
space complexity = O(1) */