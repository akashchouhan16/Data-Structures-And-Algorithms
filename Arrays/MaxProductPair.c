#include<stdio.h>
#include<stdlib.h>
//Similar to Finding the Largest Sum Pair from an Unsorted Input Array.
void MaxProductpair(int *arr, int n) { //My Brute Force Approach. Time Complexity : O(n). 
    int max1 = INT_MIN, max2;
    for (int i=0;i<n;i++) {
        if (arr[i]>max1) {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i]<max1 && arr[i]>max2)
            max2 = arr[i];
    }
    printf("Max Product Pair is %d,%d.", max1, max2);
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        *(arr+i) = rand()%9;

    for (int i=0;i<n;i++)
        printf("%d ", *(arr + i));
    printf("\n");
    MaxProductpair(arr, n);
}