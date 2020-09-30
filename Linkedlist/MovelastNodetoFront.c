#include <stdlib.h>
#include <stdio.h>
//To Move the Last Node to the front of the linked list.
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
void MovelastNode(struct Node *p)
{
    struct Node *q;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    p->next = head;
    head = p;
}
int main()
{
    Create();
    Display(head);

    MovelastNode(head);
    Display(head);
    free(head);
    return 0;
}