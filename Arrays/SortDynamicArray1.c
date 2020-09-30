#include <stdlib.h>
#include <stdio.h>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int l, int h)
{
    int i = l, j = h;
    int pivot = *(arr + l);
    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            Swap(arr + i, arr + j);
        }
    } while (i < j);
    Swap(arr + l, arr + j);
    return j;
}
void QuickSort(int *arr, int n, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        QuickSort(arr, n, l, p);
        QuickSort(arr, n, p + 1, h);
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
    QuickSort(a, n, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
}