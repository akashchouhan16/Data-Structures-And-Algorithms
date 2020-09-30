//Wap to Remove duplciates from an Unsorted Array.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//The Only test Case that it fails is 1 3 4 5 6 6 9.
//O/p is 1 3 4 5 6 6 and not 1 3 4 5 6. - Could be avoid by using the hash Table Method, requiring Space : O(n).
void Swap(int *x, int *y)
{
    *x = ((*x) * (*y)) / (*y = *x);
}
int partition(int *arr, int n, int l, int h)
{
    int pivot = *(arr + l);
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
        {
            Swap(arr + i, arr + j);
        }
    } while (i < j);
    Swap(arr + l, arr + j);
    return j;
}

void Sort(int *arr, int n, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, n, l, h);
        Sort(arr, n, l, p);
        Sort(arr, n, p + 1, h);
    }
}
// Required Problem is to remove the Duplicates fromt the array.
void RemoveDuplicates(int *arr, int n, int *size)
{
    int j = 0;
    *size = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j++] = arr[i];
            (*size)++;
        }
    }
    arr[j++] = arr[n - 1];
    // printf("\nOutput Array : ");
    // for (int i = 0; i < j; i++)
    //     printf("%d ", *(arr + i));
    *size = j;
}
int main()
{
    int n, n1, n2, newsize = 0;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the Element Range(n1 to n2) : ");
    scanf("%d%d", &n1, &n2);
    srand(time(0));
    for (int i = 0; i < n; i++)
        *(arr + i) = n1 + rand() % (n2 - n1 + 1);
    printf("Input Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    Sort(arr, n, 0, n); //To Sort the Array in O(nlogn).
    printf("\nSorted Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    RemoveDuplicates(arr, n, &newsize);
    printf("\nOutput Array : ");
    for (int i = 0; i < newsize; i++)
        printf("%d ", *(arr + i));

    free(arr);
    return 0;
}