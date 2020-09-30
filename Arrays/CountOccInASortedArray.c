//Gv=iven a Sorted Array you have to count the numbet of times k occurs.
#include<stdlib.h>
#include<stdio.h>


int firstOcc(int *arr, int n, int key) {
    int res = -1, l=0, mid, h=n-1;
    if (n==1)
        return 0;
    while (l<=h) {
        mid = l + (h-l)/2;
        if (arr[mid]==key) {
            res = mid;
            h = mid - 1;
        }
        else if (arr[mid]<key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return res;
}
int lastOcc(int *arr, int n, int key) {
    int res = -1, l=0, mid, h=n-1;
    if (n==1)
        return 0;
    while (l<=h) {
        mid = l + (h-l)/2;
        if (arr[mid]==key)
        {
            res = mid;
            l = mid+1;
        }
        else if (arr[mid]>key)
            h = mid - 1;
        else
            l = mid + 1;

    }
    return res;
}
int Count(int *arr, int n, int key) {
    int first = firstOcc(arr, n, key);
    int last = lastOcc(arr, n, key);
    return (last - first) + 1;
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
    printf("Number of Times %d has occ is %d\n", key, Count(arr, n, key));


}