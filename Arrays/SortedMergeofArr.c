#include <stdlib.h>
#include <stdio.h>

// the Merge function will use this.
int *Merge(int *arr1, int *arr2, int n1, int n2) //If arr1 and arr2 are sorted, then Merging will be Sorted.
{
    int *arr3 = (int *)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[k++] = arr2[j++];
        }
        else if (arr1[i] == arr2[j])
        {
            arr3[k++] = arr1[i++];
            j++;
        }
    }
    for (; i < n1; i++)
        arr3[k++] = arr1[i];
    for (; j < n2; j++)
        arr3[k++] = arr2[j];
    return arr3; //basically returning a pointer.
}
int main()
{
    int n1, n2;

    printf("Enter the size of array 1 and 2 : ");
    scanf("%d%d", &n1, &n2);
    int arr1[n1], arr2[n2]; //Static.
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    int *arr3;
    for (int i = 0; i < n1; i++)
        printf("%d ", *(arr1 + i));
    printf("\n");
    for (int i = 0; i < n2; i++)
        printf("%d ", *(arr2 + i));
    printf("\n");

    arr3 = Merge(arr1, arr2, n1, n2);
    for (int i = 0; i < (n1 + n2); i++)
        printf("%d ", *(arr3 + i));

    for (int i = 0; i < (n1 + n2); i++)
    {
        free(arr3 + i);
    }
}