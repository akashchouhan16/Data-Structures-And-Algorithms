#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
}
void ReverseList(struct Node *p)
{
    struct Node *r = NULL, *q = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
int main()
{
    struct Node *temp, *last;
    int n, ch = 1, x;
    printf("Enter 1 to create Node, 0 to Display and terminate code.");
    while (ch != 0)
    {
        printf("\nEnter choice(1/0) :");
        scanf("%d", &ch);
        if (ch != 0)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the Data : ");
            scanf("%d", &x);
            temp->data = x;
            temp->next = NULL;
            if (head == NULL)
            {
                head = last = temp;
            }
            else
            {
                last->next = temp;
                last = temp;
            }
        }
    }
    printf("Displaying the linked list : \n");
    Display(head);
    ReverseList(head);
    printf("\nReversed list : \n");
    Display(head);
}