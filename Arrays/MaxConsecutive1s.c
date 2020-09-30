#include <stdio.h>
#include <stdlib.h>

int maxConsecutive1s(int *arr, int n)
{
    int j, max = -1, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            j = i;
            while (arr[j] != 0 && j < n)
            {
                count++;
                if (count > max)
                    max = count;
                j++;
            }
            i = j;
            count = 0;
        }
    }
    return max;
}
int main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    // *(arr+i) = rand()%2;
    printf("Input Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\nMaximum consecutive 1s is %d", maxConsecutive1s(arr, n));
    free(arr);
}