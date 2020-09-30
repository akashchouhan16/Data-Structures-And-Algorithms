#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    srand(time(0));
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

void rearrange(struct Node *p)
{
    struct Node *Odd, *Even, *Evenhead;
    if (head == NULL)
        return;
    Odd = p;
    Even = p->next;
    Evenhead = Even;
    while (1)
    {
        if (Odd == NULL || Even == NULL || Even->next == NULL)
        {
            Odd->next = Evenhead;
            break;
        }
        Odd->next = Even->next;
        Odd = Even->next;
        if (Odd->next == NULL)
        {
            Even->next = NULL;
            Odd->next = Evenhead;
            break;
        }
        Even->next = Odd->next;
        Even = Odd->next;
    }
    head = p;
}
void ReverseList(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p)
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
    Create();
    Display(head);
    // ReverseList(head);
    printf("All Odd position Nodes are present Before all Even position Nodes.\n");
    rearrange(head);
    Display(head);
    free(head);
    return 0;
}