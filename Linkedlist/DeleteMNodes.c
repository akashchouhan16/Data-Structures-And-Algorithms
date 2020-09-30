//Wap to Delete Mnodes after n nodes in a sll.
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

void Display(struct Node *p)
{
    if (p)
    {
        printf("%d->", p->data);
        Display(p->next);
    }
    else
    {
        printf("NULL\n");
    }
}

void Create()
{
    struct Node *temp;
    int ch;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->data = rand() % 10;

        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        printf("Do you want to create another node? (1/0) : ");
        scanf("%d", &ch);

    } while (ch == 1);
}
void Delete() //Indexing Starts from 0.
{
    int x = -1, m, n;
    printf("Enter n(th node) : ");
    scanf("%d", &n);
    printf("Enter the m no. of nodes : ");
    scanf("%d", &m);
    while (m > 0)
    {
        m--;
        struct Node *p = head, *q;
        if (n == 0)
        {
            while (p != NULL)
            {
                q = p;
                p = p->next;
                free(q);
            }
        }
        if (head == NULL)
        {
            printf("The list is empty.\n");
            return;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                q = p;
                p = p->next;
            }
            if (p)
            {
                q->next = p->next;
                free(p);
                p = q->next;
                if (p)
                {
                    tail = p;
                }
                else
                {
                    tail = q;
                }
            }
        }
    }
}

int main()
{
    Create();
    Display(head);

    Delete();
    Display(head);
    free(head);
    return 0;
}