#include<stdio.h>
#include<stdlib.h>

void rightRotate(int *arr, int low, int high, int shiftCount) {
    int temp;
    while (shiftCount) {
        temp = arr[high];
        for (int i=high;i>=low;i--) {
            arr[i] = arr[i-1];
        }
        arr[low] = temp;
        shiftCount--;
    }
}
void leftRotate(int *arr, int low, int high, int shiftCount) {
    int temp;
    while (shiftCount) {
        temp = arr[low];
        for (int i =low;i<high;i++) {
            arr[i] = arr[i+1];
        }
        arr[high] = temp;
        shiftCount--;
    }
}
int main() {
    int n, count, low, high, ch=1;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i =0;i<n;i++)
        *(arr+i) = 1 + rand()%9;

    printf("Input Array : ");
    for (int i =0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\nEnter the Index range : ");
    scanf("%d%d", &low, &high);
    printf("Enter 1 to perform Right Shift || Enter 2 to perform Left Shift :");
    scanf("%d", &ch);
    if (ch==1) {
        printf("Enter the Number of right Shifts required : ");
        scanf("%d", &count);

        rightRotate(arr, low, high, count);
        printf("\nNew Array : ");
        for (int i =0;i<n;i++)
            printf("%d ", *(arr+i));
        free(arr);
    }
    else {
        printf("Enter the Number of Left Shifts required : ");
        scanf("%d", &count);

        leftRotate(arr, low, high, count);
        printf("\nNew Array : ");
        for (int i =0;i<n;i++)
            printf("%d ", *(arr+i));
        free(arr);
    }

}
