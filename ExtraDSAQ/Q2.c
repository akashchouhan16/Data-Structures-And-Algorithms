#include <stdio.h>
#include <stdlib.h>

void ReverseDyarray(int *p, int size)
{
    int i, j;
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        int temp = *(p + i);
        *(p + i) = *(p + j);
        *(p + j) = temp;
    }
    i = 0;
    while (i < size)
    {
        printf("%d ", *(p + i));
        i++;
    }
}
int main()
{
    int *arr;
    int n, n1, n2, i;
    printf("Enter the Dynamic array size : ");
    scanf("%d", &n);
    printf("Enter the range of your input \nLower then Upper range : ");
    scanf("%d%d", &n1, &n2);
    arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        *(arr + i) = n1 + rand() % (n2 - n1 + 1);
    printf("INPUT : ");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\nOUTPUT : ");
    ReverseDyarray(arr, n);
    free(arr);
}