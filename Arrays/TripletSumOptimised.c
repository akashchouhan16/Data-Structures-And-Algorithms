#include <stdlib.h>
#include <stdio.h>
//Approach is to Sort the Array in O(nlogn) then apply binary search approach to find the triplet.
// Time Complexity of the Whole program is reduced to O(n^2) from O(n^3).

void Swap(int *x, int *y)
{
    // (*x ^= *y), (*y ^= *x), (*x ^= *y);
    // int temp = *x;
    // *x = *y;
    // *y = temp;
    *x = ((*y) * (*x)) / (*y = *x);
}
int partition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
            Swap(arr + i, arr + j);
    } while (i < j);
    Swap(arr + l, arr + j);
    return j;
}
void Quick(int *arr, int n, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        Quick(arr, n, l, p);
        Quick(arr, n, p + 1, h);
    }
}

void FindTriplets(int *arr, int n, int sum) //Time Complexity is O(n^2).
{
    int l, h = n - 1;
    for (int i = 0; i < n; i++)
    {
        l = i + 1;
        while (l < h)
        {
            if (arr[i] + arr[l] + arr[h] == sum)
            {
                printf("{%d,%d,%d} ", arr[i], arr[l], arr[h]);
                l++;
            }
            else if (arr[i] + arr[l] + arr[h] > sum)
            {
                h--;
            }
            else if (arr[i] + arr[l] + arr[h] < sum)
                l++;
        }
    }
}

int main()
{
    int n, n1, n2, sum;
    printf("Enter the array size : ");
    scanf("%d", &n);
    printf("Enter the Range of the array elements : ");
    scanf("%d%d", &n1, &n2);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        *(arr + i) = n1 + rand() % (n2 - n1 + 1);

    printf("Input Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    Quick(arr, n, 0, n); //Array has been Sorted.
    printf("\nEnter the Sum : ");
    scanf("%d", &sum);
    FindTriplets(arr, n, sum);

    free(arr);
    return 0;
}