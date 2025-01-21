#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void maxHeapify(int A[], int i, int n)
{
    int l = 2*i, r = 2*i + 1, largest = i, temp;
    if( l<=n && A[l] > A[largest])
        largest = l;
    if( r<=n && A[r] > A[largest])
        largest = r;   
    if (largest != i)     
    {
        temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        maxHeapify(A, largest, n);
    }
}

void buildMaxheap(int A[], int n)
{
    for(int i = n/2; i>=1; i--)
    {
        maxHeapify(A, i, n);
    }
}

void heapSort(int A[], int n)
{
    buildMaxheap(A,n);
    int i, temp;
    for(i=n; i>=2; i--)
    {
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        n = n-1;
        maxHeapify(A, 1, n);
    }
}
void display(int A[], int n)
{
    int i;
    for(i = 1; i<=n; i++)
        printf("%d ", A[i]);
    printf("\n");

}
int main()
{
    int i, n, A[100000], diff;
    clock_t start, end;
    srand(time(NULL));
    printf("How much n? -> ");
    scanf("%d ", &n);
    for(i = 1; i<=n; i++)
        A[i] = rand();
    display(A, n);
    start = clock();
    heapSort(A,n);
    end = clock();
    diff = end - start;
    display(A,n);
    printf("Time = %.6f seconds\n", (double)((diff)/CLOCKS_PER_SEC));
    return 0;
}