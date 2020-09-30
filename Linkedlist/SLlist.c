#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

void Display(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d->", p->data);
        Display(p->next);
    }
    else
        printf("NULL\n");
}
int Count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void ReverseList(struct Node *p)
{
    struct Node *r = NULL, *q = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
void InsertionTolist(struct Node *p, int pos, int x)
{
    struct Node *temp;
    if (pos < 1 || pos > Count(p))
    {
        printf("Invalid Position");
        return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = tail = temp;
    }
    // if (pos == 1)
    // {
    //     //Insertion at head.
    //     temp->next = head;
    //     head = temp;
    // }
    else
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            temp->next = p->next;
            p->next = temp;
        }
    }
}
int Delete(struct Node *p, int pos)
{
    int x = -1;
    struct Node *q = NULL;
    if (pos < 1 || pos > Count(p))
        return -1;
    if (pos == 1)
    { //Assuming indexing starts from 1 to n;
        q = head;
        head = head->next;
        x = q->data;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
void Create()
{
    struct Node *temp;
    int ch = 1;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        printf("Enter Data : ");
        scanf("%d", &temp->data);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        printf("Do you want to create another Node? (1/0) ");
        scanf("%d", &ch);
    } while (ch == 1);
}

int main()
{
    int choice;
    Create();
    Display(head);
    printf("Enter 1 to Count the Number of Nodes\nEnter 2 to Reverse the List\nEnter 3 to perform Insertion\nEnter 4 to Delete Node\nEnter the terminate Program\n");
    do
    {
        printf("Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("No. of Nodes in the list is : ", Count(head));
        }
        else if (choice == 2)
        {
            ReverseList(head);
            Display(head);
        }
        else if (choice == 3)
        {
            int x, index;
            printf("Enter the data to insert : ");
            scanf("%d", &x);
            printf("Enter the position : ");
            scanf("%d", &index);
            InsertionTolist(head, index, x);
            printf("New List is : \n");
            Display(head);
        }
        else if (choice == 4)
        {
            int i;
            printf("enter the index to delete the Node : ");
            scanf("%d", &i);
            int res = Delete(head, i);
            printf("Node Deleted with Value %d\nNewlist is\n", res);
            Display(head);
        }

    } while (choice != 0);
    free(head);
    return 0;
}