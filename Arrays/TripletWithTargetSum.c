#include <stdio.h>
#include <stdlib.h>

void FindTriplet(int *arr, int n, int sum)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    printf("{%d,%d,%d}, ", arr[i], arr[j], arr[k]);
                }
            }
        }
    }
}
int main()
{
    int n, n1, n2, sum;
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
    printf("\nEnter Sum : ");
    scanf("%d", &sum);
    FindTriplet(arr, n, sum);
    free(arr);
    return 0;
}