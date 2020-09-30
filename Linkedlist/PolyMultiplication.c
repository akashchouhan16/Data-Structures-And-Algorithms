#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

void Display(struct Node *ptr)
{
    if (ptr != NULL)
    {
        if (ptr->next != NULL)
        {
            printf("%d X^%d +", ptr->coef, ptr->exp);
            Display(ptr->next);
        }
        else
        {
            printf("%d", ptr->coef);
            Display(ptr->next);
        }
    }
    else
        printf("\n");
}

void Create(struct Node **head, struct Node **tail, int size)
{
    struct Node *temp;

    for (int i = size; i >= 0; i--)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->exp = i;
        printf("\nFor Exponent %d :", temp->exp);
        printf("\nEnter the Coefficient : ");
        scanf("%d", &temp->coef);

        if (*head == NULL)
        {
            *head = *tail = temp;
        }
        else
        {
            (*tail)->next = temp;
            *tail = temp;
        }
    }
}

void Multiply(struct Node **head, struct Node **tail, struct Node *ptr1, struct Node *ptr2)
{
    struct Node *temp, *ptr3 = ptr2, *pos;

    while (ptr1 != NULL)
    {
        ptr2 = ptr3;

        while (ptr2 != NULL)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->next = NULL;

            temp->coef = ptr1->coef * ptr2->coef;
            temp->exp = ptr1->exp + ptr2->exp;

            if (*head == NULL)
            {
                *head = *tail = temp;
            }
            else
            {
                (*tail)->next = temp;
                *tail = temp;
            }
            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }

    ptr3 = *head;

    while (ptr3 != NULL)
    {
        pos = ptr3->next;
        temp = ptr3;

        while (pos != NULL)
        {
            if (ptr3->exp == pos->exp)
            {
                ptr3->coef = ptr3->coef + pos->coef;
                temp->next = pos->next;
            }
            temp = pos;
            pos = pos->next;
        }
        ptr3 = ptr3->next;
    }
}

int main()
{
    struct Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
    struct Node *head3 = NULL, *tail3 = NULL; //Resultant Linked List
    int size1, size2;

    printf("\nEnter the highest exponent of first equation: ");
    scanf("%d", &size1);
    Create(&head1, &tail1, size1);
    Display(head1);

    printf("\nEnter the highest exponent of second equation: ");
    scanf("%d", &size2);
    Create(&head2, &tail2, size2);
    Display(head2);

    printf("\n**POLYNOMIAL MULTIPLICATION***\n\n");

    Multiply(&head3, &tail3, head1, head2);
    Display(head3);

    free(head1);
    free(head2);
    free(head3);
    return 0;
}