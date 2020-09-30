#include<stdio.h>
#include<stdlib.h>

void NextGreatestElement(int *arr, int n) {
    int currentMax, temp;
    currentMax = arr[n-1];
    arr[n-1] = -1;

    for (int i=n-2;i>=0;i--) {
        temp = arr[i];
        arr[i] = currentMax;
        if (currentMax<temp)
            currentMax = temp;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
        scanf("%d", arr+i);
    // *(arr+i) = 1 + rand()%9;
    printf("Input Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
    NextGreatestElement(arr, n);
    printf("Output Array : ");
    for (int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
    free(arr);

}