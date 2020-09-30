#include<stdio.h>
#include<stdlib.h>

void Sort(int *arr, int n) {
    int j, x;
    for (int i = 1;i<n;i++) {
        x = *(arr+i);
        j = i-1;
        while (j>-1 && *(arr+j)>x) {
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = x;
    }
}

void Resultantarray(int *arr1, int *arr2, int n1, int n2) {
    int size = (n1>n2)?n1:n2;
    int *arr3 = (int *)malloc(size*sizeof(int));
    int i=0, j=0, k=0;
    while (i<n1 && j<n2) {
        if (*(arr1+i)<*(arr2+j)) {
            i++;
        }
        else if (*(arr1+i)>*(arr2+j)) {
            j++;
        }
        else if (*(arr1+i)==*(arr2+j)) {
            arr3[k++] = arr1[i++];
            j++;
        }
    }
    printf("\nIntersection of two array : ");
    for (int i =0;i<k;i++)
        printf("%d ", *(arr3+i));
    free(arr3);

}
int main() {
    int n1, n2;
    printf("Enter Size of array 1 : ");
    scanf("%d", &n1);
    printf("Enter Size of array 2 : ");
    scanf("%d", &n2);
    int *arr1 = (int*)malloc(n1*sizeof(int));
    int *arr2 = (int*)malloc(n2*sizeof(int));
    for (int i = 0;i<n1;i++)
        *(arr1+i) = 1 + rand()%9;
    Sort(arr1, n1);
    for (int i = 0;i<n2;i++)
        *(arr2+i) = 4 + rand()%14;
    Sort(arr2, n2);
    printf("Array 1 : ");
    for (int i = 0;i<n1;i++)
        printf("%d ", *(arr1+i));
    printf("\nArray 2 : ");
    for (int i = 0;i<n2;i++)
        printf("%d ", *(arr2+i));

    Resultantarray(arr1, arr2, n1, n2);

    free(arr1);
    free(arr2);
}