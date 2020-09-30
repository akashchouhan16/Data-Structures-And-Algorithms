#include<stdio.h>
int revstr(char A[],int n,char B[],int temp)
{
    static int i=0;
    if(n>=0)
    {
        B[i]=A[n];
        i++;
        revstr(A,n-1,B,temp);
    }
    else
    {
        int j;
        for(j=0;j<temp;j++)
        printf("%d",B[j]);

    }

}
int main()
{

    int n,temp;
    scanf("%d",&n);
    char A[n],B[n];
    scanf("%s",A);
    temp=n;

    revstr(A,n-1,B,temp);
}
