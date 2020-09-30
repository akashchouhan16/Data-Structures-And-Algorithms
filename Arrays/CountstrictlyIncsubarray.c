//Wap to Count the number of strictly Increasing subarrays of an unsorted input array.
// i/p : {1,2,2,4}, o/p : 2 subarrays i.e, 1,2 and 2,4
#include<stdio.h>
#include<stdlib.h>

int CountInc(int *arr, int n) {
    //A less Optimal Solution - O(m), where m is the no. of the subarrays in the output.
    int count = 0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;i++) {
            if (arr[j]>arr[j-1])
                count++;
            else
                break;
        }
    }
    return count;
}


int CountIncsubarrays(int *arr, int n) { //Most Optimal Solution
    int len = 1, count = 0; //len keeps track of the subarray size that is sorted.

    for (int i=0;i<n-1;i++) {
        if (arr[i+1]>arr[i]) // Increasing
            len++;
        else {
            count+= ((len*(len-1))/2);
            len = 1;
        }
    }
    if (len>1)
        count+=((len*(len-1))/2);

    return count;
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("Input Array \n");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n No. of Strictly Increasinf subarrays are %d", CountIncsubarrays(arr, n));
    printf("\n No. of Strictly Increasinf subarrays are %d", CountInc(arr, n));
}
