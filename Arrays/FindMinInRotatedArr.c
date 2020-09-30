//To Find the minimum/smallest element in a Sorted but Rotated array.
//Most Optimal apprach is by binary Search - O(log n).

#include <stdio.h>
#include <stdlib.h>

int findMinElement(int *arr, int n)
{
    int l = 0, h = n - 1, mid = 0;
    if (n == 1) //case of a singular array.
        return arr[0];
    if (*(arr + l) < *(arr + h)) // In case of Sorted and not Rotated.
        return *(arr + l);

    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (l<mid &&*(arr + mid - 1)> * (arr + mid))
            return *(arr + mid);
        else if (h > mid && *(arr + mid + 1) < *(arr + mid))
            return *(arr + mid + 1);
        else if (*(arr + h) > *(arr + mid))
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    printf("Minimum element is %d.", findMinElement(arr, n));
}