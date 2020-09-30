//DeleteNodesinSLL that Contain prime numbers.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node **head)
{
    struct Node *temp, *p = *head;
    int ch = 0;
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
        printf("Node Created!Do you want to Create Another Node?(1/0) :");
        scanf("%d", &ch);
    } while (ch == 1);
}
void Display(struct Node *p)
{
    if (p)
    {
        printf("%d->", p->data);
        Display(p->next);
    }
    else
        printf("Null\n");
}

int isPrime(int x)
{
    int c = 0;
    if (x == 0 || x == 1)
    {
        return 0; //they are not prime.
    }
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            c++;
        }
    }
    return (c > 0) ? 0 : 1;
}
void DeletePrimeNodes(struct Node **head)
{
    struct Node *p = *head, *q = NULL;
    //Base Case considering Head shift.
    if (isPrime((*head)->data))
    {
        *head = (*head)->next;
        free(p);
        p = *head;
    }
    //Do not use else here.
    while (p)
    {
        if (isPrime(p->data))
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        if (isPrime(p->data) != 1)
        {
            q = p;
            p = p->next;
        }
    }
}

int main()
{
    struct Node *head1 = NULL;
    Create(&head1);
    Display(head1);
    DeletePrimeNodes(&head1);
    Display(head1);

    free(head1);
    return 0;
}