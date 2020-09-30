#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
} *head1 = NULL, *head2 = NULL, *temp = NULL, *temp2 = NULL;

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
void Displayalt(struct Node *p) //Shortcut to match the test case.
{
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
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
        // temp->data = 1 + rand() % 9;
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
struct Node *DivideList(struct Node **newTemp)
{
    struct Node *p = head1;
    struct Node *temptail = temp;
    struct Node *temp2tail = temp2;
    while (p && p->next)
    {
        if (temp == NULL)
        {
            temp = temptail = p;
            temp2 = temp2tail = p->next;
            p = p->next->next;
        }

        else
        {
            temptail->next = p;
            temptail = p;
            temp2tail->next = p->next;
            temp2tail = p->next;
            p = p->next->next;
            temptail->next = NULL;
        }
    }
    *newTemp = temp2;
    return temp;
}

int main()
{
    Create(&head1);
    // Create(&head2);
    Display(head1);
    // Display(head2);
    struct Node *new;
    struct Node *new2;
    new = DivideList(&new2);
    printf("New List with All Even and Odd position Nodes Segregated : \n");

    Displayalt(new);
    Display(new2);
    free(new);
    free(new2);
    free(head1);
    // free(head2);
    return 0;
}