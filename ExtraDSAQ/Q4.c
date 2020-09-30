#include<stdio.h>
#include<stdlib.h>

int Solution(int *arr, int n) {
    int len = 1, max = INT_MIN;
    for (int i = 0;i<n;i++) {
        if (arr[i+1]>arr[i])
            len++;
        if (len>max) {
            max = len;
        }
        else if (arr[i+1]<arr[i])
            len = 1; //Resetting Len of subarray.
    }

    return max;
}
int main() {
    int *arr;
    int n, n1, n2, i;
    printf("Enter the Dynamic array size : ");
    scanf("%d", &n);
    printf("Enter the range of your input \nLower then Upper range : ");
    scanf("%d%d", &n1, &n2);
    arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        *(arr + i) = n1 + rand() % (n2 - n1 + 1);
    printf("INPUT : ");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    printf("\nThe max number of Consecutive elements present is asc. order are %d\n", Solution(arr, n));
    free(arr);
}