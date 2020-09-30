#include <stdlib.h>
#include <stdio.h>

void getBinary(int num)
{
    int size = 8;
    if (num > 255)
        size = 16;
    int *arr = (int *)calloc(size, sizeof(int));
    int i = 0, rem = 0, temp = num;
    while (temp != 0 && i < size)
    {
        rem = temp % 2;
        *(arr + i) = rem;
        temp = temp / 2;
        i++;
    }
    printf("\nBinary Equvalent : ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", *(arr + i));
    }
    free(arr);
}
int main()
{
    int num;
    printf("Enter the decimal number : ");
    scanf("%d", &num);
    getBinary(num);
}