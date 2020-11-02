#include <stdio.h>
#include <stdlib.h>
//Only Works for a few cases. Has minor bug.
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
void UtilityforSort(struct Node **head, struct Node *new)
{
    struct Node *current = NULL;
    if ((*head) == NULL || (*head)->data >= new->data)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        current = *head;
        while (current->next && current->next->data < new->data)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
    return;
}
void InsertionSort(struct Node *head)
{
    struct Node *head2 = NULL; //for new list.
    struct Node *curr = head;
    while (curr)
    {
        struct Node *next = curr->next;
        UtilityforSort(&head2, curr);
        curr = next;
    }
    head = head2;
    return;
}
int main()
{
    struct Node *head = NULL;
    Create(&head);
    printf("List : ");
    Display(head);
    InsertionSort(head);
    printf("New List : ");
    Display(head);
    free(head);
    return 0;
}
