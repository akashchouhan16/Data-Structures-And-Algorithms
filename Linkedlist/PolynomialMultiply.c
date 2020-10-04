#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
} *head3 = NULL; //For resultant list.

void Create(struct Node **head)
{
    struct Node *temp, *p = *head;
    int ch, n;
    printf("Enter the number of non-zero terms of the Polynomial : ");
    scanf("%d", &n);
    while (n > 0)
    {
        n--;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        printf("Enter Coeff and expo : ");
        scanf("%d%d", &temp->coeff, &temp->expo);
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
    printf("Data Saved in the List.\n");
}

void Display(struct Node *p)
{
    if (p)
    {
        if (p->next)
        {
            printf("%dX^(%d) + ", p->coeff, p->expo);
            Display(p->next);
        }
        else
            printf("%d\n", p->coeff);
    }
    else
        return;
}
void MultiplyPolynomial(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1, *ptr2 = head2, *temp = NULL, *ptr3 = head3;
    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->next = NULL;
            temp->coeff = ptr1->coeff * ptr2->coeff;
            temp->expo = ptr1->expo + ptr2->expo;
            if (head3 == NULL)
            {
                head3 = ptr3 = temp;
            }
            else
            {
                ptr3->next = temp;
                ptr3 = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    //Now combining equal expo terms.
    ptr3 = head3;
    struct Node *q;
    while (ptr3 != NULL)
    {
        q = ptr3->next;
        temp = ptr3;

        while (q != NULL)
        {
            if (ptr3->expo == q->expo)
            {
                ptr3->coeff = ptr3->coeff + q->coeff;
                temp->next = q->next;
            }
            temp = q;
            q = q->next;
        }
        ptr3 = ptr3->next;
    }
}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    Create(&head1);
    Create(&head2);
    Display(head1);
    Display(head2);
    MultiplyPolynomial(head1, head2);
    Display(head3);
    free(head1);
    free(head2);
    return 0;
}