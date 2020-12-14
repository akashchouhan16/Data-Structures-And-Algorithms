#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    printf("Enter the Range (n1 to n2) :");
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
void DeleteLastOcc(struct Node *head, int key)
{
    struct Node *p = head, *q = NULL, *temp = NULL;
    while (p)
    {
        if (p->data == key)
        {
            temp = p;
        }
        p = p->next;
    }
    q = head;
    p = head->next;
    while (p != temp)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    p = q->next;
    return;
}
int main()
{
    struct Node *head = NULL;
    Create(&head);
    printf("List : ");
    Display(head);
    int key;
    printf("Enter the key : ");
    scanf("%d", &key);
    DeleteLastOcc(head, key);
    printf("New List : ");
    Display(head);
    free(head);
    return 0;
}