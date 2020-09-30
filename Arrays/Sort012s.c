#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//Dutch National Flag Algorithm.
void MySort(int *arr, int n)
{
    int l = 0, mid = 0, h = n - 1;
    while (mid <= h)
    {
        if (*(arr + mid) == 0)
        {
            Swap(arr + mid, arr + l);
            l++;
            mid++;
        }
        else if (*(arr + mid) == 2)
        {
            Swap(arr + mid, arr + h);
            h--;
        }
        else
            mid++;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        *(arr + i) = rand() % 3;
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    MySort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
}