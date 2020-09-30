#include<stdio.h>
#include<stdlib.h>

void Swap(int *x, int *y) {
    (*x^=*y), (*y^=*x), (*x^=*y);
}

void ReversepositionEven(int *arr, int n) {
    int j, x = (n%2==0)?n-2:n-1;
    for (int i=0, j=x;i<j;i=i+2, j=j-2) {
        Swap(arr+i, arr+j);
    }
}
void ReversepositionOdd(int *arr, int n) {
    int j, x = (n%2==0)?n:n-1;
    for (int i=1, j=x-1;i<j;i=i+2, j=j-2) {
        Swap(arr+i, arr+j);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0;i<n;i++)
        *(arr+i) = 1 + rand()%9;
    // scanf("%d", arr+i);
    printf("Input Array : ");
    for (int i = 0;i<n;i++)
        printf("%d ", *(arr+i));

    printf("\nArray when Even index positon elements are swapped : ");
    ReversepositionEven(arr, n);
    for (int i = 0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\nArray when Odd index positon elements are swapped from the new array : ");
    ReversepositionOdd(arr, n);
    for (int i = 0;i<n;i++)
        printf("%d ", *(arr+i));
    free(arr);
    return 0;
}