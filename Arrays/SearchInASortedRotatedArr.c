//Basic approach is to perform Linear Search in O(n) time. Efficient solution will be to perform Binary Search
//and search in O(logn) time.
#include<stdlib.h>
#include<stdio.h>

//Weird Error with one input : 4 5 6 7 0 1 2 3, key = 6, say Not found if return -1 is present.
int findelementIndex(int *arr, int n, int key) {
    int l = 0, mid, h = n-1;
    if (n==0)
        return -1;
    while (l<h) {
        mid = l + (h-l)/2;
        if (arr[mid]==key)
            return mid;
        if (arr[l]<=arr[mid]) {
            if (key<=arr[mid] && key>=arr[l])
                h = mid - 1;
            else
                l = mid + 1;
        }
        else {
            if (key>=arr[mid] && key<=arr[h])
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
    // return -1;
}
int binSearchtoRotatedArr(int *arr, int n, int key) {
    int l = 0, mid, h = n-1;
    if (n==0)
        return -1;
    while (l<h) {
        mid = l + (h-l)/2;
        if (arr[mid]==key)
            return mid;
        if (arr[l]<=arr[mid]) {
            if (key>=arr[l] && key<=arr[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        else {
            if (key>=arr[mid] && key<=arr[h]) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }

        }
    }
    return -1;
}
int main() {
    int n, key;
    printf("Enter the size : ");
    scanf("%d", &n);
    int *arr= (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        scanf("%d", arr+i);
    printf("Enter the Search Key : ");
    scanf("%d", &key);
    if (findelementIndex(arr, n, key)!=-1)
        printf("The Element if Found at Index %d\n", findelementIndex(arr, n, key));
    else
        printf("Element Not Found!\n");
    if (binSearchtoRotatedArr(arr, n, key)!=-1)
        printf("The Element if Found at Index %d", binSearchtoRotatedArr(arr, n, key));
    else
        printf("Element Not Found!");
    free(arr);
}