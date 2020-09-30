#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

void Display(struct Node *p)
{
    if (p)
    {
        printf("%d->", p->data);
        Display(p->next);
    }
    else
    {
        printf("NULL\n");
    }
}

void Create()
{
    struct Node *temp;
    int ch;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->data = rand() % 10;

        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        printf("Do you want to create another node? (1/0) : ");
        scanf("%d", &ch);

    } while (ch == 1);
}
void DeleteMiddleNode(struct Node *p)
{
    struct Node *q = head, *temp;
    while (p!=NULL && p->next != NULL)
    {
        temp = q; //Tail pointer to q, i.e middle.
        q = q->next;
        p = p->next->next;
    }
    temp->next = q->next;
    int x = q->data;
    free(q);
    printf("Node with Data %d deleted.\n", x);
    return;
}

int main()
{
    Create();
    Display(head);
    DeleteMiddleNode(head);
    Display(head);
    free(head);
    return 0;
}
