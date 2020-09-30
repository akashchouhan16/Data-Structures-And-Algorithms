//To find the missing element of array size n-1, having elements from 0 to n.
#include <stdio.h>
#include <stdlib.h>

int findMissing(int *arr, int n)
{
    int total = 0;
    total = ((n + 1) * (n + 2)) / 2;
    for (int i = 0; i < n; i++)
        total -= *(arr + i);

    return total;
}
int OptimisedSoln(int *arr, int n)
{
    //Using XOR(^) operator.
    int X1, X2;
    for (int i = 0; i < n; i++)
        X1 ^= *(arr + i);
    for (int k = 0; k <= n; k++) // 1 to n or 0 to n will give the same result.
        X2 ^= k;
    return X1 ^ X2;
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("The Missing element is %d\n", findMissing(arr, n));
    printf("The Missing element is %d\n", OptimisedSoln(arr, n));
}