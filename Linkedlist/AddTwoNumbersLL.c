#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void Create(struct Node **head, struct Node **tail, int val)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = val;
    if (*head == NULL)
    {
        *head = *tail = temp;
        return;
    }
    else
    {
        (*tail)->next = temp;
        *tail = temp;
    }
}
void Display(struct Node *head)
{
    while (head)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
    return;
}
struct Node *AddNumbers(struct Node *h1, struct Node *h2)
{
    struct Node *h3 = NULL, *t3 = NULL;
    int carry = 0, current_sum = 0, req_digit = 0;
    while (h1 != NULL || h2 != NULL)
    {
        int h1data = (h1 != NULL) ? h1->data : 0;
        int h2data = (h2 != NULL) ? h2->data : 0;

        current_sum = h1data + h2data + carry;
        carry = current_sum / 10;
        req_digit = current_sum % 10;
        Create(&h3, &t3, req_digit);
        if (h1 != NULL)
            h1 = h1->next;
        if (h2 != NULL)
            h2 = h2->next;
    }
    return h3;
}
int main()
{
    struct Node *h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
    int num1, num2;
    printf("Enter Num1 and Num2 : ");
    scanf("%d%d", &num1, &num2);
    int temp = num1;
    while (temp)
    {
        int digit = temp % 10;
        Create(&h1, &t1, digit);
        temp /= 10;
    }
    Display(h1);
    temp = num2;
    while (temp)
    {
        int digit = temp % 10;
        Create(&h2, &t2, digit);
        temp /= 10;
    }
    Display(h2);

    //Required Solution : h1 points to units' place digit. Req : to Add val using ll.
    struct Node *result = NULL, *t3 = NULL;
    result = AddNumbers(h1, h2);
    printf("Sum of the Two Numbers : ");
    Display(result);
    free(h1);
    free(h2);
    free(result);
    return 0;
}