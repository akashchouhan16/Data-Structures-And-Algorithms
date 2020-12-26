#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// Binary Search on Dynamic Array.

void SortData(int *arr, int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = *(arr + i);
        j = i - 1;
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
    return;
}
void RandomInput(int *arr, int n)
{
    int n1, n2;
    printf("Enter range : ");
    scanf("%d %d", &n1, &n2);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = n1 + rand() % (n2 - n1 + 1);
    }
    SortData(arr, n);
    return;
}

void Display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    return;
}
void binarySeach(int *arr, int n)
{
    int key;
    printf("Enter search query : ");
    scanf("%d", &key);
    int l = 0, h = n - 1, mid;
    int flag = 0;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        if (*(arr + mid) == key)
        {
            printf("%d Found at index : %d\n", key, mid);
            flag = 1;
            break;
        }
        else if (*(arr + mid) > key)
        {
            h = mid - 1;
        }
        else if (*(arr + mid) < key)
            l = mid + 1;
    }
    if (!flag)
        printf("%d Not Found!\n", key);
    return;
}
int main()
{
    int *arr;
    int m;
    printf("Enter dynamic arraym : ");
    scanf("%d", &m);
    arr = (int *)malloc(sizeof(int) * m);
    printf("Initialized..\n");
    RandomInput(arr, m);
    Display(arr, m);
    binarySeach(arr, m);
    free(arr);
    return 0;
}