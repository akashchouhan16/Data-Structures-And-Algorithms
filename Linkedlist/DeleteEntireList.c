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
    printf("Enter Range (n1 to n2) : ");
    scanf("%d%d", &n1, &n2);
    srand(time(0));
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
void DeleteList(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }
    struct Node *p = (*head)->next, *q = *head;
    while (p)
    {
        q->next = p->next;
        printf("%d deleted,", p->data);
        free(p);
        p = q->next;
    }
    free(q);
    printf("List Deleted!\n");
    *head = NULL;
    return;
}
int main()
{
    struct Node *head = NULL;
    Create(&head);
    printf("List : ");
    Display(head);
    DeleteList(&head);
    free(head);
    return 0;
}