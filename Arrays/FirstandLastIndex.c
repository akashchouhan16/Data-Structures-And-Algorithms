//To find the first and the last index of an element in a sorted array.
#include<stdlib.h>
#include<stdio.h>

void getFirstandLast(int *arr, int n, int key) {
    int i = 0, firstocc = -1, lastocc = -1;
    for (i=0;i<n;i++) {
        if (*(arr+i)==key) {
            firstocc = i;
            lastocc = i; //temporarily.
            break;
        }
    }
    for (;i<n;i++) {
        if (*(arr+i)==key)
            lastocc = i;
    }
    printf("\nFirst Occurence of %d is %d\nLast Occurrence of %d is %d\n", key, firstocc, key, lastocc);
    return;
}
int main() {
    int n, key;
    printf("Enter the size : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        *(arr+i) = 1 + rand()%18;
    printf("Input Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\nEnter key : ");
    scanf("%d", &key);
    getFirstandLast(arr, n, key);
    free(arr);
}