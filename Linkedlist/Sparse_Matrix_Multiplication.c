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



void Multiply(struct Node **head, struct Node **tail, struct Node *ptr1, struct Node *ptr2)
    {
        if (ptr1->c != ptr2->r)
        {
        printf("Not possible");
        return;
        }

        struct Node *temp, *temp1, *temp2;      //temp is a new node for the resultant matrix, temp1 is the node for sparse matrix1, temp2 is the node for sparse matrix2
        
        temp1=ptr1->next;                       //Since the header nodes doesnt contain the actual values 
        temp2=ptr2->next;

        if (*head == NULL)
            {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->next = NULL;
                temp->data = 0;
                temp->r = ptr1->r;
                temp->c = ptr2->c;
                *head = *tail = temp;
            }

        float product = 0, pos1 = 0, pos2 = 0;         //pos1 will contain the temp1(data,i,k) and pos2 will contain temp2(data,k,j)

        for (int i = 0; i < ptr1->r; i++)
        {
            for (int j = 0; j < ptr2->c; j++) 
            {
                product = 0;
                for (int k = 0; k < ptr1->c; k++) {

                    pos1 = 0, pos2 = 0;
                    while (temp1 != NULL)
                    {
                        if (temp1->r == i && temp1->c == k)
                        {
                            pos1=temp1->data;
                        }
                        temp1=temp1->next;
                    }

                    while (temp2 != NULL)
                    {
                        if (temp2->r == k && temp2->c == j)
                        {
                            pos2=temp2->data;
                        }
                        temp2=temp2->next;
                    }
                    product += pos1 * pos2;
                    
                temp1=ptr1->next;
                temp2=ptr2->next;
                }
                    
                    if (product != 0) {
                        temp = (struct Node *)malloc(sizeof(struct Node));
                        temp->next = NULL;
                        temp->data=product;
                        temp->r=i;
                        temp->c=j;
                        
                        (*head)->data = (*head)->data + 1;
                        
                        (*tail)->next = temp;
                        (*tail) = temp;

                    
                }
            }
        }
    }

int main()
{
    struct Node *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL;     //2 sparse matrix linked lists
    struct Node *head3=NULL, *tail3=NULL, *ptr;                               //Resultant Linked List
    
    int r1,r2,c1,c2;

    r1=2;
    c1=3;
  
    int a[2][3]={7,0,0,1,2,2};                                          //Sparse Matrix 1

    for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d  ",a[i][j]);
            }
        printf("\n");
        }
    
    printf("\n");

    r2=3;
    c2=3;

    int b[3][3]={7,0,0,0,0,0,2,0,3};                                    //Sparse Matrix 2

    for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d  ",b[i][j]);
            }
        printf("\n");
        }
    
    printf("\n*******SPARSE MATRIX 1******\n");
    sparse(&head1,&tail1,r1,c1,a);
    Display(head1);

    printf("\n*******SPARSE MATRIX 2******\n");
    sparse(&head2,&tail2,r2,c2,b);
    Display(head2);

    printf("\n*******SPARSE MATRIX MULTIPLICATION******\n");
    Multiply(&head3,&tail3,head1,head2);
    Display(head3);

    ptr=head3->next;

    printf("\n");
    for (int i = 0; i < head3->r; i++)
    {
        for (int j = 0; j < head3->c; j++)
        {
            if(ptr->r==i && ptr->c==j)
                {
                    printf("%d | ", ptr->data);
                    ptr=ptr->next;
                }
            else
                {
                    printf("0 | ");
                }
            
        }
    printf("\n"); 
    }
    

    free(head1);
    free(head2);
    free(head3);
    return 0;
}