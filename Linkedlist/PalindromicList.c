#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node **head)
{
    struct Node *temp = NULL, *p = *head;
    int ch;

    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
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
        printf("Create Another?(1/0) : ");
        scanf("%d", &ch);
    } while (ch == 1);
    return;
}

void Display(struct Node *p)
{
    if (p)
    {
        printf("%d->", p->data);
        Display(p->next);
    }
    else
        printf("NULL\n");
}
struct Node *Reverse(struct Node **head)
{
    struct Node *q = NULL, *r = NULL;
    do
    {
        r = q;
        q = *head;
        *head = (*head)->next;
        q->next = (*head);
    } while (*head);
    *head = q;
    return *head;
}
bool checkPalindrome(struct Node *head)
{
    struct Node *h1 = head;
    struct Node *h2 = Reverse(&head);
    Display(head);
    struct Node *p = h1, *q = h2;
    while (p && q)
    {
        if (p->data != q->data)
            return false;

        p = p->next;
        q = q->next;
    }
    return true;
}
int main()
{
    struct Node *head = NULL;
    Create(&head);
    printf("List : ");
    Display(head);
    printf("\nIs it Palindromic List? %s", checkPalindrome(head) ? "YES" : "NO");
    free(head);
    return 0;
}