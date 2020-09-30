#include<stdio.h>
int main()
{
    int A[10]={8,3,6,4,6,5,6,8,2,7};
    int max=8;
    int H[9]={0};
    int i;
    for(i=0;i<10;i++)
        H[A[i]]++;

    for(i=1;i<=max;i++)
    {
        if(H[i]>1)
        {
            printf("%d appears %d times",i,H[i]);
            printf("\n");
        }
    }
}
