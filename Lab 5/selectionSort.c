#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort( int A[], int n)
{
    int i, least, pos, temp, j;
    for(i=0; i<n; i++)
    {
        least = A[i];
        pos = i;

        for(j = i+1; j<n; j++)
        {
            if(A[j] < least)
            {
                least = A[j];
                pos = j;
            }
        }

        if (i!= pos)
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
    for(i = 0; i<n; i++)
        printf("%d", A[i]);
        printf("\n");
    printf("\n");

}
int main()
{
    int i, n, A[100000], diff;
    clock_t start, end;
    srand(time(NULL));
    printf("How much n? -> ");
    scanf("%d ", &n);
    for(i = 0; i<n; i++)
        A[i] = rand();
    display(A, n);
    start = clock();
    selectionSort(A,n);
    end = clock();
    diff = end - start;
    display(A,n);
    printf("Time = %.6f seconds\n", (float)((diff)/CLOCKS_PER_SEC));
    return 0;
}