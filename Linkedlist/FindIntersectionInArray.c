#include <stdio.h>
#include <stdlib.h>

void Intersections(int *arr1, int *arr2, int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    int m = (n1 > n2) ? n2 : n1;
    int *arr3 = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr3[k++] = arr1[i];
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr3[i]);
    }
    free(arr3);
}
int main()
{
    int n1, n2;
    printf("Enter the size 1 : ");
    scanf("%d", &n1);
    printf("Enter the size 2 : ");
    scanf("%d", &n2);
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
        scanf("%d", arr1 + i);
    for (int i = 0; i < n2; i++)
        scanf("%d ", arr2 + i);
    printf("Array1 : ");
    for (int i = 0; i < n1; i++)
        printf("%d ", *(arr1 + i));
    printf("\nArray2 : ");
    for (int i = 0; i < n2; i++)
        printf("%d", *(arr2 + i));
    printf("\nIntersection : ");
    Intersections(arr1, arr2, n1, n2);
    return 0;
}