#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
    // (*x ^= *y), (*y ^= *x), (*x ^= *y);
    // int temp = *x;
    // *x = *y;
    // *y = temp;
    *x = ((*y) * (*x)) / (*y = *x);
}
int partition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
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
            Swap(arr + i, arr + j);
    } while (i < j);
    Swap(arr + l, arr + j);
    return j;
}
void Quick(int *arr, int n, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        Quick(arr, n, l, p);
        Quick(arr, n, p + 1, h);
    }
}

int main()
{
    int n, n1, n2;
    printf("Enter the array size : ");
    scanf("%d", &n);
    printf("Enter the Range of the array elements : ");
    scanf("%d%d", &n1, &n2);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        *(arr + i) = n1 + rand() % (n2 - n1 + 1);

    printf("Input Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    Quick(arr, n, 0, n);
    printf("\nOutput Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    free(arr);
    return 0;
}