#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y) {
    (*x^=*y), (*y^=*x), (*x^=*y);
}
void bubbleSort(int *arr, int n) {
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (*(arr+j)>*(arr+j+1))
                swap(arr+j, arr+j+1);
        }
    }
}
/* ====== QuickSort in O(nlogn) Time. ===========*/
int partition(int *A, int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int *arr, int n, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr, n, l, p);
        quickSort(arr, n, p + 1, h);
    }
}

void printUnielements(int *arr, int n) {
    int j = 0;
    for (int i=0;i<n;i++) {
        if (arr[i]!=arr[i+1]) {
            arr[j++] = arr[i];

        }
    }
    for (int i=0;i<j;i++)
        printf("%d ", *(arr+i));
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr  = (int*)malloc(n*sizeof(int));

    for (int i=0;i<n;i++)
        *(arr+i) = 1 + rand()%8;
    printf("INPUT array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
    bubbleSort(arr, n); //Sorts the input array.
    printf("INPUT after Sorting : ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\nOUTPUT array of Unique elements : ");

    printUnielements(arr, n);
}