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
        printf("Create Another? (1/0) : ");
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
//A Modified Linear Search On SLL, that would make the Key Node the Head Node to Reduce the Time Complexity if the Same Node is Search again.
void LinearSearch(struct Node **head, int key, int *position)
{
    *position = 0; //for Not Found.
    struct Node *p = *head, *q = *head;
    if ((*head)->data == key)
    {
        *position = 0;
    }
    p = p->next;
    *position += 1;
    while (p && p->data != key)
    {
        q = p;
        p = p->next;
        *position = *position + 1;
    }
    if (q && p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = *head;
            *head = p; //Also Updating the head, by making the key Node the head Node.
        }
    }
    else
    {
        *position = -1;
        //Not Found.
    }
    return;
}

int main()
{
    struct Node *head = NULL;
    Create(&head);
    printf("List : ");
    Display(head);
    int key, index;
    printf("Enter -99 as key to terminated the Code\n");
    do
    {
        printf("Enter the Search Key : ");
        scanf("%d", &key);
        LinearSearch(&head, key, &index);
        if (index == -1)
        {
            printf("Key Node Not Found.\nList Not Updated!\n");
        }
        else
        {
            printf("Key Node Found at index %d!\nNew List : ", index);
            Display(head);
        }
    } while (key != -99);

    free(head);
    printf("Code terminated\n");
    return 0;
}