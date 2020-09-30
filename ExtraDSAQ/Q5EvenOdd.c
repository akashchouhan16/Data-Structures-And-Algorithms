#include<stdio.h>
#include<stdlib.h>

void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void SortEvenOdd(int *arr, int n) {
    int i=0, j=n-1;
    while ((n%2==0)?i<j:i<=j) {
        if (*(arr+i)%2==0)
            i++;
        if (*(arr+j)%2!=0)
            j--;
        if (*(arr+i)%2!=0 && *(arr+j)%2==0) {
            Swap(arr+i, arr+j);
            i++;
            j--;
        }

    }
}

int main() {
    int *arr;
    int n, i;
    printf("Enter the Dynamic array size : ");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // *(arr + i) = n1 + rand() % (n2 - n1 + 1);
    printf("INPUT : ");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    SortEvenOdd(arr, n);
    printf("\nOUTPUT : \n");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr+i));
    free(arr);
}