#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
int merge(struct Array *arr1,struct Array *arr2,struct Array *arr3)
{
    int i=0,j=0,k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
         arr3->A[k]=arr1->A[i];
         k++;
         i++;
        }
        else
        {
            arr3->A[k]=arr2->A[j];
            k++;
            j++;
        }

    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k]=arr1->A[i];
        k++;
        i++;
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k]=arr2->A[j];
        k++;
        j++;
    }

}
int display(struct Array arr1,struct Array arr2,struct Array arr3)
{
    int i;
    for(i=0;i<(arr1.length+arr2.length);i++)
        printf("%d ",arr3.A[i]);
}
int main()
{
    struct Array arr1,arr2,arr3;
    printf("Enter size for 1st array:\n");
    scanf("%d",&arr1.size);
    printf("Enter size for 2nd array:\n");
    scanf("%d",&arr2.size);
    printf("Enter actual no.of elements for 1st array:\n");
    scanf("%d",&arr1.length);
    printf("Enter actual no.of elements for 2nd array:\n");
    scanf("%d",&arr2.length);
    arr1.A=(int*)malloc(arr1.size*sizeof(int));
    arr2.A=(int*)malloc(arr2.size*sizeof(int));
    arr3.A=(int*)malloc((arr1.size+arr2.size)*sizeof(int));


    int i,j;

    printf("Enter elements for 1st array\n");
    for(i=0;i<arr1.length;i++)
        scanf("%d",&arr1.A[i]);

    printf("Enter elements for 2nd array\n");
    for(j=0;j<arr2.length;j++)
        scanf("%d",&arr2.A[j]);

        merge(&arr1,&arr2,&arr3);
        display(arr1,arr2,arr3);




}
