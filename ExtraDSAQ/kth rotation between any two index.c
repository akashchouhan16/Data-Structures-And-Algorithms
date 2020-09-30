#include<stdio.h>
#include<stdlib.h>
int main()
{

    int i,j,n,s,e,count=0,x;
    printf("Enter n\n");
    scanf("%d",&n);
    int *p=(int*)malloc(n*sizeof(int));
    printf("Input elements\n");
    for(i=0;i<n;i++)
        scanf("%d",p+i);

    printf("Enter starting and end index\n");
    scanf("%d%d",&s,&e);
    printf("Enter number of right rotations\n");
    scanf("%d",&count);

    while(count!=0)
    {
        for(i=e;i>=s;i--)
        {
            if(i==e)
                x=p[i];
            else
            {
             p[i+1]=p[i];
            }
        }
        p[s]=x;
        count--;
    }
    printf("Updated array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",p[i]);

        free(p);
}
