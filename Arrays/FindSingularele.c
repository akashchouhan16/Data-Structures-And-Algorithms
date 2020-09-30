#include <stdio.h>
#include <stdlib.h>
//Element that occurs only once in a sorted array.

void findSingular(int *arr, int n) {
    int i, HT[101] ={ 0 };
    for (i=0;i<n;i++) {
        HT[arr[i]]++;
    }
    for (i=0;i<n;i++) {
        if (HT[arr[i]]==1)
            printf("%d ", arr[i]);
    }
}


void Find(int *arr, int n)
{
    int res = -1;
    int i, j = 0;
    while (j<n) {
        for (i = 0; i < n; i++)
        {
            if (*(arr + i) != *(arr + i + 1))
                res = *(arr + i); // potential element.
        }
        j++;
        printf("%d ", res);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the array elements : \n");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    findSingular(arr, n);
}