#include <stdio.h>
#include <stdlib.h>

int getOddoccurrence(int *arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    //A^0 = A and A^A = 0.
    return res;
}
int BruteForceSoln(int *arr, int n)
{
    int HT[101] = {0}; //assuming the range to be b/w 0 to 100
    for (int i = 0; i < n; i++)
    {
        HT[arr[i]] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (HT[arr[i]] % 2 != 0)
        {
            return arr[i];
        }
    }
}
int main()
{
    int n;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("The Odd occ element is %d", getOddoccurrence(arr, n));
    printf("\nThe Odd occ ele (by Hashing Soln) is %d", BruteForceSoln(arr, n));
}