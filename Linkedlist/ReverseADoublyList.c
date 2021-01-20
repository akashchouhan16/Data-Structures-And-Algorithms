#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} List;

void Create(List **head)
{
    List *temp = NULL, *ptr = *head;
    int n1, n2, ch;
    printf("Enter a Range : ");
    scanf("%d%d", &n1, &n2);
    do
    {
        temp = (List *)malloc(sizeof(List));
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = n1 + rand() % (n2 - n1 + 1);
        if (!ptr)
        {
            *head = ptr = temp;
        }
        else
        {
            ptr->next = temp;
            temp->prev = ptr;
            ptr = temp;
        }
        printf("Node Created! create another?(1/0) : ");
        scanf("%d", &ch);
    } while (ch == 1);
    return;
}
void Display(List *head)
{
    if (head)
    {
        printf("%d<=>", head->data);
        Display(head->next);
    }
    else
    {
        printf("NULL\n");
        return;
    }
}

void ReverseList(List **head)
{
    List *temp = NULL, *curr = *head;
    if (!curr)
        return;
    else
    {
        while (curr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
    }
    if (temp)
        *head = temp->prev;
    return;
}

int main()
{
    List *head = NULL;
    Create(&head);
    printf("Input List : ");
    Display(head);
    ReverseList(&head);
    printf("Output List : ");
    Display(head);
    free(head);
    return 0;
}