#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

void Display(struct Node *p)
{
    do
    {
        printf("%d->", p->data);
        p = p->next;
    } while (p != head);
    printf("head(%d)\n", head->data);
}
int Count(struct Node *p)
{
    static int flag = 0;
    static int count = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        count++;
        Count(p->next);
    }
    else
        return count;
}
void Create()
{
    int ch = 0;
    struct Node *temp;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data : ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (head == NULL)
        {
            head = tail = temp;
            tail->next = head;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
        printf("Do You want to create another node?(1/0) : ");
        scanf("%d", &ch);

    } while (ch == 1);
    if (head->data == tail->next->data) //Verification of CLL.
        printf("\nCircular Linked list Created.\n");
}
void InsertToCLL(int pos)
{
    struct Node *temp, *p = head;
    if (pos < 0) //Assuming indexing from 0 to n.
    {
        printf("Invalid Position\n");
        return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (pos == 0) //Case where inserted Node is to be made the head Node.
    {
        temp->next = head;
        tail->next = temp;
        head = temp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p->next != head)
        {
            temp->next = p->next;
            p->next = temp;
        }
        else if (p == tail || p->next == head) //OR p->next == head.
        {
            tail->next = temp;
            temp->next = head;
        }
    }
}
int Deletion(struct Node *p, int pos)
{
    int data = -1;
    struct Node *q = head;
    if (pos < 1)
        return -1;
    if (head == NULL)
    {
        printf("List is Empty.\n");
    }
    else
    {
        if (pos == 1)
        {
            tail->next = head->next;
            data = head->data;
            free(head);
            head = tail->next;
        }
        else
        {
            for (int i = 0; i < pos - 1; i++)
            {
                q = p;
                p = p->next;
            }
            if (p)
            {
                q->next = p->next;
                data = p->data;
                free(p);
                p = q->next;
            }
        }
    }
    return data;
}
int isLoop(struct Node *p)
{
    struct Node *q = head;
    do
    {
        p = p->next;
        q = q->next;
        if (p)
            p = p->next;

    } while (p && q && p != q);

    return (p == q) ? 1 : 0;
}

int main()
{
    int choice;
    Create();
    Display(head);
    printf("Does linked list contain a loop ? %d\n", isLoop(head));
    printf("Enter 1 to Perform Insertion\nEnter 2 to Count the number of Nodes\nEnter 3 to perform Deletion\nEnter 0 to terminate Code\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int pos;
            printf("Enter the position : ");
            scanf("%d", &pos);
            InsertToCLL(pos);
            Display(head);
        }
        else if (choice == 2)
        {
            printf("Number of Nodes : %d", Count(head));
        }
        else if (choice == 3)
        {
            int pos;
            printf("Enter the position : ");
            scanf("%d", &pos);
            Deletion(head, pos);
            Display(head);
        }
    } while (choice != 0);
    printf("\nHead's Data : %d\n", head->data);
    Display(head);

    free(head);
}