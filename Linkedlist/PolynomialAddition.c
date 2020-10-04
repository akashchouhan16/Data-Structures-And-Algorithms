#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *head1 = NULL, *head2 = NULL;

void Create(struct Node **head, int n)
{
    struct Node *temp, *p = head1;
    while (n > 0)
    {
        n--;
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the Coeff and expo : ");
        scanf("%d%d", &temp->coeff, &temp->exp);
        temp->next = NULL;

        if (*head == NULL)
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
    }
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%dX(^%d) + ", p->coeff, p->exp);
        p = p->next;
    }
    printf("0\n");
}
void Join(struct Node **head1, struct Node *head2)
{
    struct Node *p = *head1;
    if (*head1 == NULL)
    {
        *head1 = head2;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head2;
}
void Add()
{
    struct Node *ptr = head1, *q = head1;
    struct Node *ptrNext = ptr->next;
    for (; ptr != NULL; ptr = ptr->next)
    {
        q = ptr;
        ptrNext = ptr->next;
        for (; ptrNext != NULL; q = ptrNext, ptrNext = ptrNext->next)
        {
            if (ptr->exp == ptrNext->exp)
            {
                ptr->coeff += ptrNext->coeff;
                q->next = ptrNext->next;
                free(ptrNext);
                ptrNext = q;
            }
        }
    }
}

int main()
{
    int n1, n2;
    printf("enter the number of terms for poly1 : ");
    scanf("%d", &n1);
    printf("Enter the number of terms for poly2 :");
    scanf("%d", &n2);
    printf("Enter data for Poly 1 : \n");
    Create(&head1, n1);
    printf("Enter Data for Poly 2 : \n");
    Create(&head2, n2);
    Display(head1);
    Display(head2);

    Join(&head1, head2);
    // Display(head1);
    Add();
    printf("The Summation Value : ");
    Display(head1);
    free(head1);
    return 0;
}