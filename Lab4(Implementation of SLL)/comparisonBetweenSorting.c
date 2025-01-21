#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int n)
{
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIdx])
                minIdx = j;
        }
        temp = A[i];
        A[i] = A[minIdx];
        A[minIdx] = temp;
    }
}

void insertionSort(int A[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void merge(int A[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
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
    int i, n, A[100001], diff;
    clock_t start, end;

    srand(time(NULL));

    printf("How much n? -> ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        A[i] = rand();

    int B[n], C[n], D[n];

    for (i = 0; i < n; i++)
    {
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
    }

    printf("Original Array:\n");
    display(A, n);

    // Selection Sort Timing
    start = clock();
    selectionSort(B, n);
    end = clock();
    printf("Selection Sort Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Insertion Sort Timing
    start = clock();
    insertionSort(C, n);
    end = clock();
    printf("Insertion Sort Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Merge Sort Timing
    start = clock();
    mergeSort(D, 0, n - 1);
    end = clock();
    printf("Merge Sort Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\nSorted Array:\n");
    display(A, n);

    return 0;
}
