#include<stdio.h>
#include<stdlib.h>

void Search(int *arr, int n, int key) {
    for (int i = 0;i<n;i++) {
        if (*(arr+i)==key) {
            printf("Element found at index %d.\n", i);
            return;
        }
    }
    printf("Element Not Found!");

}
int main() {
    int *arr;
    int n, n1, n2, i, key;;
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

    printf("Enter the key to Seacrh : ");
    scanf("%d", &key);
    Search(arr, n, key);

    free(arr);
}