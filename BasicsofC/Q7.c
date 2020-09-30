#include <stdio.h>

int Sum(int a[], int size, int i)
{
    if (i == (size - 1))
        return a[size - 1];
    else
        return a[i] + Sum(a, size, i + 1);
}
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    sum = Sum(arr, n, 0);
    printf("\nSum of elements is %d", sum);
}