#include<stdlib.h>
#include<stdio.h>

void Delete(int *arr, int n, int pos) {
    for (int i=pos;i<n;i++) {
        arr[i] = arr[i+1];
    }
    n--;
    printf("NEW Array : \n");
    for (int i=0;i<n;i++) {
        printf("%d ", *(arr+i));
    }
}
void DeleteEvenIndex(int *arr, int n) {
    for (int i=0;i<n;i++) {
        if (arr[i]%2==0) {
            for (int j=i;j<n;j++) {
                arr[j] = arr[j+1];
            }
            n--;
        }

    }
    printf("\nNEW Array : \n");
    for (int i=0;i<n;i++) {
        printf("%d ", *(arr+i));
    }
}
int main() {
    int *arr;
    int n, n1, n2, i, index;
    printf("Enter the Dynamic array size : ");
    scanf("%d", &n);
    printf("Enter the range of your input \nLower then Upper range : ");
    scanf("%d%d", &n1, &n2);
    arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", arr+i);
    // *(arr + i) = n1 + rand() % (n2 - n1 + 1);
    printf("INPUT : ");
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    // printf("\nEnter the index to delete the element : ");
    // scanf("%d", &index);
    // Delete(arr, n, index);
    DeleteEvenIndex(arr, n);
}