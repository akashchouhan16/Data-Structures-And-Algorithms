#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node **head)
{
    struct Node *temp = NULL, *p = *head;
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
        printf("Create Another?(1/0) : ");
        scanf("%d", &ch);
    } while (ch == 1);
    return;
}

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
struct Node *IntersectionList(struct Node *head1, struct Node *head2)
{
    struct Node *head3 = NULL, *tail = NULL, *p = head1, *q = head2;
    struct Node *temp = NULL;
    if (!head1 || !head2)
    {
        printf("No Intersecting Points\n");
        return NULL;
    }
    while (p)
    {
        q = head2;
        while (q)
        {
            if (p->data == q->data)
            {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->next = NULL;
                temp->data = p->data;
                if (head3 == NULL)
                {
                    head3 = tail = temp;
                }
                else
                {
                    tail->next = temp;
                    tail = temp;
                }
            }
            q = q->next;
        }
        p = p->next;
    }
    Display(head3);
    free(head3);
    return NULL;
}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    Create(&head1);
    Create(&head2);
    printf("List 1 : ");
    Display(head1);

    printf("List 2 : ");
    Display(head2);
    printf("\nIntersections : ");
    IntersectionList(head1, head2);
    free(head1);
    free(head2);
    return 0;
}