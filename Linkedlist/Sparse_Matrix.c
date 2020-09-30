#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int r;
    int c;
    struct Node *next;
};

void Display(struct Node *ptr)
{
    if (ptr != NULL)
    {    
        printf("(%d,%d,%d) => ", ptr->data,ptr->r,ptr->c);
        Display(ptr->next);
    }
    else
        printf("NULL\n");   
    
}

void sparse(struct Node **head, struct Node **tail, int row, int col, int arr[row][col])
{
    struct Node *temp;

        if (*head == NULL)
            {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->next = NULL;
                temp->data = 0;
                temp->r = row;
                temp->c = col;
                *head = *tail = temp;
            }
        
    
    for (int i = 0; i < row; i++)
    {    
        for (int j = 0; j < col; j++)
        {
            if(arr[i][j]!=0)
                {
                    temp = (struct Node *)malloc(sizeof(struct Node));
                    temp->next = NULL;
                    temp->data = arr[i][j];
                    temp->r = i;
                    temp->c = j;
                    
                    (*head)->data = (*head)->data + 1;
                    (*tail)->next = temp;
                    *tail = temp;
                    
                }
        }
        
    }       
}

int main()
{
    struct Node *head1=NULL, *tail1=NULL, *ptr;     //1 sparse matrix linked list

    int r1,c1,size=0;

    r1=3;
    c1=3;
  
    int a[3][3]={5,0,0,0,0,0,1,0,3};                                          //Sparse Matrix 1

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d  ",a[i][j]);
        }
    printf("\n");
    }
    

    
    printf("\n*******SPARSE MATRIX 1 USING LINKED LIST******\n");
    sparse(&head1,&tail1,r1,c1,a);
    Display(head1);

    printf("\n*******SPARSE MATRIX 1 USING ARRAY******\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (a[i][j]!=0)
            { 
                size++;
            }
            
        }
    }
    
    struct Node* arr[size+1];

    arr[0]=(struct Node*)malloc(sizeof(struct Node));
    arr[0]->data=0;
    arr[0]->r=r1;
    arr[0]->c=c1;

    int k=1;

    ptr=head1->next;

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (a[i][j]!=0)
            {
                arr[k]=(struct Node*)malloc(sizeof(struct Node));
                arr[k]->data=a[i][j];
                arr[k]->r=i;
                arr[k]->c=j;
                k++;
            }
            
        }
        
    }
    
    for (int i = 0; i <= size; i++)
    {
        printf("(%d, %d, %d) | ",arr[i]->data,arr[i]->r,arr[i]->c);
    }
    

    free(head1);
    return 0;
}