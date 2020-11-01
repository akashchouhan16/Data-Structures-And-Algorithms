#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *next;
};
int digits(int n)
{
    return (int)log10((int)n) + 1;
}
void Create(struct Node **head, int number)
{
    struct Node *temp = NULL, *p = *head;
    int size = digits(number);
    do
    {
        size--;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->data = number % 10;
        number /= 10;
        if (*head == NULL)
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
    } while (size);
    printf("List Created!\n");
    return;
}
void Display(struct Node *head)
{
    if (head)
    {
        printf("%d->", head->data);
        Display(head->next);
    }
    else
        printf("NULL\n");
}
void Reverse(struct Node **head)
{
    struct Node *p = *head, *q = NULL, *r = NULL;
    do
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    } while (p);
    *head = q;
    return;
}
void AddOne(struct Node *head)
{
    struct Node *p = head, *temp = NULL;
    int carry = 1, sum = 0;
    while (p)
    {
        sum = carry + ((p) ? p->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        p->data = sum;
        temp = p;
        p = p->next;
    }
    if (carry > 0)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->next = NULL;
        t->data = carry;
        temp->next = t;
    }
    return;
}

int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    printf("Digits : %d\n", digits(num));
    struct Node *num1 = NULL;
    Create(&num1, num);
    Reverse(&num1);
    Display(num1);
    Reverse(&num1);
    AddOne(num1);
    Reverse(&num1);
    Display(num1);
    // Reverse(&num1);
    // Display(num1);
    free(num1);
    return 0;
}