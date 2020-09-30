#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head = NULL, *tail = NULL;

// int Count(struct Node *p)
// {
//     int c = 0;
//     while (p)
//     {
//         c++;
//         p = p->next;
//     }
//     return c;
// }
void Display(struct Node *p)
{
    if (p)
    {
        printf("%d<=>", p->data);
        Display(p->next);
    }
    else
        printf("NULL\n");
}
void Create()
{
    struct Node *temp;
    int ch;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->next = NULL;
        printf("Enter the Data : ");
        scanf("%d", &temp->data);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        printf("Do you Want to Create another Node? (1/0) : ");
        scanf("%d", &ch);
    } while (ch == 1);
}

int Deletion(struct Node *p, int pos)
{
    int x;
    if (pos < 1)
        return -1;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }
    if (pos == 1)
    {
        head = p->next;
        head->prev = NULL;
        x = p->data;
        free(p);
        return x;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p && p->next != NULL)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            x = p->data;
            free(p);
            return x;
        }
        else if (p && p->next == NULL)
        {
            p->prev->next = NULL;
            x = p->data;
            free(p);
            return x;
        }
    }
}

int main()
{
    Create();
    Display(head);
    int pos;
    printf("Enter the Node positon to Delete : ");
    scanf("%d", &pos);
    int res = Deletion(head, pos);
    printf("%d has been deleted.\n New list \n", res);
    Display(head);
    free(head);
    return 0;
}
