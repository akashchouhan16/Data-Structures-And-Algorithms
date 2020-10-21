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
//Solution:
void Rotate(struct Node **head, int k)
{
    struct Node *q = NULL, *p = *head;
    if (*head == NULL)
    {
        printf("Error : Empty List.\n");
        return;
    }
    while (k--)
    {
        while (p && p->next)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        p->next = *head;
        *head = p;
    }
    return;
}
int main()
{
    struct Node *head = NULL;
    int k;
    Create(&head);
    Display(head);
    printf("Enter the Number of Clockwise Rotations required  : ");
    scanf("%d", &k);
    Rotate(&head, k);
    printf("New Singly Linked List : \n");
    Display(head);
    free(head);
    return 0;
}