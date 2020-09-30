#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
int BinSrch(struct Array arr,int l,int h,int key)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
        return mid;
        else if(arr.A[mid]>key)
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;

}
int main()
{

    struct Array arr;
    printf("Enter Size\n");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc((arr.size)*sizeof(int));
    printf("Enter Elements\n");
    int i,key;
    for(i=0;i<arr.size;i++)
        scanf("%d",&arr.A[i]);

        printf("Enter Key\n");
        scanf("%d",&key);

        int l=0;
        int h=(arr.size)-1;
        printf("The element is present at index:%d",BinSrch(arr,l,h,key));





}
