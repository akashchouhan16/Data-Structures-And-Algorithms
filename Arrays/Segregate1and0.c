#include<stdio.h>
#include<stdlib.h>

void Segregate(int *arr, int n) { //Related it with sort0s,1sn2s question. Time Complexity : O(n).
    int l = 0, m = 0;
    for (int i=0;i<n;i++) {
        if (arr[m]==0) {
            int temp = arr[m];
            arr[m] = arr[l];
            arr[l] = temp;
            l++;
            m++;
        }
        else
            m++;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0;i<n;i++)
        *(arr+i) = rand()%2;
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
    Segregate(arr, n);
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
    free(arr);

}