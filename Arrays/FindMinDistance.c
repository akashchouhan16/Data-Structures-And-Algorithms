//To find the minimum distance between x and y in a given array that may have duplicates.
#include <stdio.h>
#include <stdlib.h>
int MinDistance(int *arr, int n) //BruteForce approach in O(n^2) time complexity.
{
    int x, y, min = INT_MAX;
    printf("Enter x and y : ");
    scanf("%d%d", &x, &y);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] == x && arr[j] == y || arr[j] == x && arr[i] == y)
            {
                if (abs(i - j) < min)
                    min = abs(i - j);
            }
        }
    }
    return min;
}
int minDist(int *arr, int n) //O(n). Optimal Approach.
{
    int i, x, y, min = INT_MAX, prev;
    printf("Enter x and y : ");
    scanf("%d%d", &x, &y);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x || arr[i] == y)
        {
            prev = i;
            break;
        }
    }
    for (; i < n; i++)
    {
        if (arr[i] == x || arr[i] == y)
        {
            if (arr[prev] != arr[i] && (i - prev) < min)
            {
                min = i - prev;
                prev = i;
            }
            else
                prev = i;
        }
    }
    return min;
}
int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("%d\n", MinDistance(arr, n));
    printf("%d\n", minDist(arr, n));
    free(arr);
}