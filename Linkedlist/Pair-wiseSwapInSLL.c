#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node **head)
{
    struct Node *temp = NULL, *p = *head;
    int ch, n1, n2;
    printf("Enter the LL element Range(n1 to  n2) : ");
    scanf("%d%d", &n1, &n2);
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->data = n1 + rand() % (n2 - n1 + 1);
        if (*head == NULL)
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
        printf("Node Created! Create another?(1/0) : ");
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
void PairwiseSwap(struct Node **head)
{
    struct Node *p = *head, *q = (*head)->next;
    struct Node *temp = NULL;
    *head = q;
    while (1)
    {
        q = p->next;
        temp = q->next;
        q->next = p;
        if (temp == NULL)
        {
            p->next = NULL;
            break;
        }
        if (temp->next == NULL)
        {
            p->next = temp;
            break;
        }
        p->next = temp->next;
        p = temp;
    }
    return;
}
int main()
{
    struct Node *head = NULL;
    Create(&head);
    Display(head);
    PairwiseSwap(&head);
    Display(head);
    free(head);
    return 0;
}