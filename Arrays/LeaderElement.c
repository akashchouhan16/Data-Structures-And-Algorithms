#include<stdio.h>
#include<stdlib.h>


void findleaderelements(int *arr, int n) { //O(n^2) // Some problem with the Code.(logical)
    for (int i=0;i<n-2;i++) {
        int j;
        for (j=i+1;j<n;j++) {
            if (arr[i]<=arr[j])
                break;
        }
        if (j==n) {
            printf("%d ", arr[i]);
        }
    }
}
void OptimisedLeaderElement(int *arr, int n) { //O(n).
    int max = arr[n-1];
    printf("%d ", arr[n-1]);
    for (int i=n-2;i>=0;i--) {
        if (max<arr[i]) {
            max = arr[i];
            printf("%d ", max);
        }
    }
}

int main() {
    int n;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        *(arr+i) = 1 + rand()%18;
    printf("INPUT array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
    // findleaderelements(arr, n);
    OptimisedLeaderElement(arr, n);

    free(arr);
    printf("\nMemory freed.");
}