#include<stdio.h>
#include<stdlib.h>

void Delete(int *arr, int *n, int pos) {
    int k = *n;
    for (int i=pos;i<=k;i++) {
        arr[i] = arr[i+1];
    }
    *n =*n - 1;
}
int main() {

    int n, pos;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[30];
    for (int i=0;i<n;i++)
        *(arr+i) = 1+rand()%9;
    printf("Input Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\nEnter the index to Delete the element : ");
    scanf("%d", &pos);
    Delete(arr, &n, pos);
    printf("New Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
}
