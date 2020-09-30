#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
} *head1 = NULL, *head2 = NULL;

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }

    printf("NULL\n");
}
void Create(struct Node **head)
{
    srand(time(0));
    struct Node *temp, *p = *head;
    int ch;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        printf("Enter Data : ");
        scanf("%d", &temp->data);

        if (*head == NULL)
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
        printf("Do you want to create another node? (1/0) : ");
        scanf("%d", &ch);

    } while (ch == 1);
}
void Concatenate(struct Node **head1) //Extra.
{
    struct Node *p = *head1;
    while (p->next)
    {
        p = p->next;
    }
    p->next = head2;
}
struct Node *SortedMerge(struct Node *p, struct Node *q)
{
    struct Node *third = NULL, *last = NULL;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else if (q->data < p->data)
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
        last->next = q;

    return third;
}

int main()
{
    printf("For List 1(Sorted)\n");
    Create(&head1);
    printf("For list 2(Sorted)\n");
    Create(&head2);
    Display(head1);
    Display(head2);
    // Concatenate(&head1);
    struct Node *head3;
    head3 = SortedMerge(head1, head2);
    Display(head3);
    free(head1);
    free(head2);
    free(head3);
    return 0;
}