#include <stdio.h>
#include <stdlib.h>
//To find the element whose ocurrence is more than n/2 times, else print NONE.
//Best Soln : By Moore's Voting Algorithm. Time- O(n), Space - O(1).
void FindMajorityEle(int *arr, int n) // NOT the best possible soln as extra space is needed.
{
    int HT[101] = {0};
    for (int i = 0; i < n; i++)
        HT[arr[i]] += 1;
    for (int i = 0; i < n; i++)
    {
        if (HT[arr[i]] > (n / 2))
        {
            printf("\n%d", arr[i]);
            return;
        }
    }
    printf("\nNONE");
}
int main()
{
    int n;
    printf("Enter the array size : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    FindMajorityEle(arr, n);
}