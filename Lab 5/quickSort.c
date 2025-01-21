#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int A[], int l, int r)
{
    int L = l, R = r, pivot = A[l], temp;
    while(L<R)
    {
        while(A[L] <= pivot)
            L++;
        while (A[R] > pivot)    
            R--;
        if (L<R) 
        {
            temp = A[L];
            A[L] = A[R];
            A[R] = temp;
        }  
    }
    temp = A[l];
    A[l] = A[R];
    A[R] = temp;
    return R;
}
void quickSort(int A[], int l, int r)
{
    int p;
    if( l<r )
    {
        p = partition(A, l, r);
        quickSort(A, l, p-1);
        quickSort(A, p+1, r);
    }
}
void display(int A[], int n)
{
    int i;
    for(i = 0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");

}
int main()
{
    int i, n, A[100000];
    clock_t start, end, diff;
    srand(time(NULL));
    printf("How much n? -> ");
    scanf("%d ", &n);
    for(i = 0; i<n; i++)
        A[i] = rand();
    // display(A, n);
    start = clock();
    quickSort(A,0, n-1);
    end = clock();
    diff = end - start;
    //display(A,n);
    printf("Time = %.6f seconds\n", (float)((diff)/CLOCKS_PER_SEC));
    return 0;
}