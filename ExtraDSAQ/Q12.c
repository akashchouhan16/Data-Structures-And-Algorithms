#include <stdlib.h>
#include <stdio.h>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Sort(int *arr, int n)
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + j) < *(arr + k))
            {
                k = j;
            }
        }
        Swap(arr + i, arr + k);
    }
}
void RemoveDuplicates(int *arr, int n)
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    printf("\nOutput Array : ");
    for (int i = 0; i < j; i++)
        printf("%d ", *(arr + i));
}

int main()
{
    int n, pos;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[30];
    for (int i = 0; i < n; i++)
        *(arr + i) = 1 + rand() % 5;
    printf("Input Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    Sort(arr, n);
    RemoveDuplicates(arr, n);
}