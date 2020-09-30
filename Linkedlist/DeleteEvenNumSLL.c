#include <stdio.h>
#include <stdlib.h>

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
        printf("NULL\n");
}
void Create()
{
    int ch;
    struct Node *temp;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        printf("Enter the data : ");
        scanf("%d", &temp->data);
        if (temp->data % 2 == 0) // A modification during the list creation itself that removes the even data in Node.
        {
            free(temp);
            goto label;
        }

        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    label:
        printf("Do you wan to create another node? (1/0) : ");
        scanf("%d", &ch);
    } while (ch == 1);
}

void DeleteEvenData(struct Node *p)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->data % 2 != 0)
        {
            q = p;
            p = p->next;
        }
        else
        {
            q->next = p->next;
            free(p);
            p = q;
        }
    }
}
int main()
{
    Create();
    Display(head);
    // DeleteEvenData(head);
    // Display(head);
    free(head);
}
