//Find the start and end Index of a subarray whose element's sum is equal to the Given sum(User's).
#include<stdio.h>
#include<stdlib.h>

void GetSubarrayIndexes(int *arr, int n, int TargetSum) {
    int sum = 0;
    for (int i =0;i<n;i++) {
        sum = arr[i];
        for (int j=i+1;j<n;j++) {
            if (sum==TargetSum)
            {
                printf("\nSum of element from index %d to %d", i, j-1);
                break;
            }
            if (sum>TargetSum)
                break;
            if (j<n) {
                sum +=arr[j];
            }
        }
    }
}
//Optimal Solution,  i.e in O(n).
void GetIndex(int *arr, int n, int target) {
    int sum = arr[0];
    int l = 0, mid = 1, h = n-1;
    while (mid<=h) {
        while (sum>target && l<=mid-1) {
            sum-= arr[l];
            l++;
        }
        if (sum==target) {
            printf("%d to %d\n", l, mid-1);
            return;
        }
        if (mid<h)
            sum+=arr[mid];

        mid++;
    }
    printf("Not Found\n");
}
int main() {
    int n, sum = 0;
    printf("Enter the size : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        *(arr+i) = 1 + rand()%9;
    // scanf("%d", arr+i);

    printf("Input Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\nEnter the Target Sum : ");
    scanf("%d", &sum);
    GetSubarrayIndexes(arr, n, sum);
    printf("\nOptimal func result : ");
    GetIndex(arr, n, sum);
}