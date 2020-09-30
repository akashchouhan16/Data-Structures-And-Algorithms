#include <stdio.h>
#include <stdlib.h>
void Solution(int arr[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i = i + 2)
    {
        temp = temp * 10 + (arr[i] % 10);
    }
    printf("%d", temp);
}
int Count(int n)
{
    int temp = n, count = 0;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    return count;
}
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    int length = Count(n);
    int *arr = (int *)malloc(length * sizeof(int));
}