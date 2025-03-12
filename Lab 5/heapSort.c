#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxHeapify(int A[], int i, int n)
{
    int l = 2 * i + 1, r = 2 * i + 2, largest = i, temp;
    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        maxHeapify(A, largest, n);
    }
}

void buildMaxHeap(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(A, i, n);
    }
}

void heapSort(int A[], int n)
{
    buildMaxHeap(A, n);
    int temp;
    for (int i = n - 1; i >= 1; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        maxHeapify(A, 0, i);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
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
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        A[i] = rand();
    display(A, n);
    start = clock();
    heapSort(A, n);
    end = clock();
    diff = (double)(end - start) / CLOCKS_PER_SEC;  //double for higher precision
    display(A, n);
    printf("Time = %.6f seconds\n", diff);
    return 0;
}
/*
best case = O(nlogn)
Worst case = O(nlogn)
space complexity = O(1) */