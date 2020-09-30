#include<stdlib.h>
#include<stdio.h>
//Not a menu driven Program as asked, but does perform Insertion at any position(first,last,middle);
void Insert(int *arr, int *n, int pos, int x) {
    int k = *n;
    for (int i=k;i>=pos;i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = x;
    *n = *n + 1;
}

int main() {

    int n, pos, x;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[30];
    for (int i=0;i<n;i++)
        *(arr+i) = 1+rand()%9;
    printf("Input Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\nEnter the index and the element to Insert : ");
    scanf("%d %d", &pos, &x);
    Insert(arr, &n, pos, x);
    printf("New Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));

}