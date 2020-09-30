#include<stdlib.h>
#include<stdio.h>

void getPair(int *arr, int n, int sum) {
    int num;
    int prev1 = INT_MIN, prev2 = INT_MIN; // To avoid multiple pairs of same digits.
    for (int i=0;i<n;i++) {
        num = sum - *(arr+i);
        for (int j=0;j<n;j++) {
            if (arr[j] == num && arr[j]!=prev2&&arr[i]!=prev1) {
                printf("(%d,%d) ", arr[i], arr[j]);
                prev1 = arr[i];
                prev2 = arr[j];
            }
        }
    }
}
int main() {
    int n, sum;
    printf("Enter the array size : ");
    scanf("%d", &n);
    printf("Enter the sum : ");
    scanf("%d", &sum);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0;i<n;i++)
        *(arr+i) = rand()%20;
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
    getPair(arr, n, sum);
}