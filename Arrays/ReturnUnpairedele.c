#include <stdlib.h>
#include <stdio.h>

int isSorted(int *arr, int n)
{
    if (n == 1 || n == 0)
        return 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (*(arr + i) > *(arr + i + 1))
            return 0;
    }
    return 1;
}
int unpaired(int *arr, int n)
{
    int X = 0, i = 0;
    while (i < n)
    {
        X ^= *(arr + i);
        i++;
    }
    return X;
}
int Find(int *arr, int n) //in case of sorted array
{
    int res = -1;
    for (int i = 0; i < n-1; i++)
    {
        if (*(arr + i) != *(arr + i + 1))
            res = *(arr + i); // potential element.
    }
    return res;
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

    if (isSorted(arr, n))
    {
        printf("\nUnpaired Element is  %d.", Find(arr, n));
    }
    else
        printf("\nUnpaired Element is %d.", unpaired(arr, n));


    free(arr);

}