#include<stdio.h>
#include<stdlib.h>

void rightRotate(int *arr, int n, int shiftCount) {
    int temp;
    while (shiftCount) {
        temp = arr[n-1];
        for (int i=n-1;i>=1;i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
        shiftCount--;
    }
}
void leftRotate(int *arr, int n, int shiftCount) {
    int temp;
    while (shiftCount) {
        temp = arr[0];
        for (int i =0;i<n;i++) {
            arr[i] = arr[i+1];
        }
        arr[n-1] = temp;
        shiftCount--;
    }
}
int main() {
    int n, count;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i =0;i<n;i++)
        *(arr+i) = 1 + rand()%9;
    printf("Input Array : ");
    for (int i =0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\nEnter the No. of Right Shifts required : ");
    scanf("%d", &count);
    rightRotate(arr, n, count);
    printf("\nNew Array : ");
    for (int i =0;i<n;i++)
        printf("%d ", *(arr+i));

    printf("\nEnter the No. of left Shifts required : ");
    scanf("%d", &count);
    leftRotate(arr, n, count);
    printf("\nNew Array : ");
    for (int i =0;i<n;i++)
        printf("%d ", *(arr+i));
    free(arr);
}