#include <stdio.h>
#include <stdlib.h>
//Using Insertion Sort to sort a Dynamic array.

void Sort(int *arr, int n) //Insertion Sort in O(n^2).
{
    int x, i, j;
    for (i = 1; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *A, int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int *arr, int n, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr, n, l, p);
        quickSort(arr, n, p + 1, h);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        *(a + i) = 1 + rand() % 9;
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    // Sort(a, n);
    quickSort(a, n, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
}
