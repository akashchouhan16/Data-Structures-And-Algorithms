#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Sort(int *arr, int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(&arr[i], &arr[k]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        *(a + i) = 1 + rand() % 18;
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    Sort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
}