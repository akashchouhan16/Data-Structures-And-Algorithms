#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// LinearSearch on a Dynamic Array.

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
    return;
}
void manualInput(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter data : ");
        scanf("%d", arr + i);
    }
    return;
}

void Display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    return;
}
void LinearSeach(int *arr, int n)
{
    int key, flag = 0;
    printf("Enter the search query : ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) == key)
        {
            printf("%d Found at index: %d\n", key, i);
            flag = 1;
            break;
        }
    }
    if (!flag)
        printf("%d Not Found!\n", key);
    return;
}
void RecursiveSearch(int *arr, int n, int key)
{
    static int i = 0;
    if (i == n)
    {
        printf("%d Not Found!\n", key);
        i = n + 1;
        return;
    }
    else if (*(arr + i) == key)
    {
        printf("%d Found at index : %d\n", key, i);
        return;
    }
    else
    {
        i++;
        RecursiveSearch(arr, n, key);
    }
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
    // manualInput(arr, m);
    Display(arr, m);
    LinearSeach(arr, m);
    free(arr);
    return 0;
}