#include <stdio.h>
#include <stdlib.h>

int MinSwap(int *arr, int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (*(arr + i) != (i + 1))
        {
            while (*(arr + i) != (i + 1))
            {
                int temp = arr[*(arr + i) - 1];
                arr[*(arr + i) - 1] = *(arr + i);
                *(arr + i) = temp;
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    // *(arr + i) = 1 + rand() % 9;
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\nMinimum Swaps to sort is %d.", MinSwap(arr, n));
    for (int i = 0; i < n; i++)
    {
        free(arr + i);
    }
}