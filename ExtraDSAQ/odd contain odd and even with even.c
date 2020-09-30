#include<stdio.h>           ///TO MAKE EVEN INDEX CONTAIN EVEN NUMBER AND ODD INDEX CONTAIN ODD NUMBER
#include<stdlib.h>
int main()
{

    int i,j,n;
    printf("Enter n\n");
    scanf("%d",&n);
    int *p=(int*)malloc(n*sizeof(int));
    printf("Input elements\n");
    for(i=0;i<n;i++)
        scanf("%d",p+i);

    i=0,j=1;
    while(i<n && j<n)
    {
        while(p[i]%2==0){i=i+2;}
        while(p[j]%2!=0){j=j+2;}

        int temp;
        temp=p[j];
        p[j]=p[i];
        p[i]=temp;

        i=i+2;
        j=j+2;


    }
    printf("Updated array is:\n");
    for(i=0;i<n;i++)
        printf("%d",p[i]);





}
