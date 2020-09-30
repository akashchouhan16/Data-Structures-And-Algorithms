#include <stdlib.h>
#include <stdio.h>

void Duplicates(int *arr, int n)
{
    int *HT = (int *)calloc((n + 1), sizeof(int));
    for (int i = 0; i < n; i++)
    {
        HT[arr[i]]++;
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (HT[i] >= 2)
        {
            printf("%d ", i);
        }
    }
    free(HT);
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        // scanf("%d", arr + i);
        *(arr + i) = 1 + rand() % (n + 1);
    printf("Input Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    printf("\nDuplicates are : ");
    Duplicates(arr, n);
}