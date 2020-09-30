#include<stdio.h>
#include<stdlib.h>

int add(int a[], int n, int i)
    {
        if(i==(n-1))
        {
            return a[n-1];
        }
        else{
            return a[i]+add(a,n,i+1);
        }
    }

int main()
{
    int n,sum=0;

    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%10;
    }

    printf("\nARRAY:  ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }

    sum=add(arr,n,0);
    printf("\nSum Of the Elements:  %d",sum);

return 0;    
}