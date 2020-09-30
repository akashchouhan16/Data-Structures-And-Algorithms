#include<stdlib.h>
#include<stdio.h>

int findPeak(int *arr, int n) {
    int ans = 0;
    if (n==1) {
        return *(arr);
    }
    for (int i=0;i<n;i++) {
        if (arr[i]>arr[i+1])
            return arr[i];
    }
    return arr[n-1];

}
int main() {
    int n;
    printf("Enter the size : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        scanf("%d", arr+i);
    printf("Peak Element is %d.\n", findPeak(arr, n));
    free(arr);
}