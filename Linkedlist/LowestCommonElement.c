#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Sample Output : 
    List 1 : 5->4->9->2->10->8->1->1->NULL
    List 2 : 18->12->20->1->10->5->NULL

    Lowest Common Element is 1  
*/
struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node **head)
{
    struct Node *temp = NULL, *p = *head;
    int ch, n1, n2;
    printf("Enter the Range (n1 to n2) :");
    scanf("%d%d", &n1, &n2);
    srand(time(0));
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->data = n1 + rand() % (n2 - n1 + 1);
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
int LowestCommonElement(struct Node *head1, struct Node *head2)
{
    int min = 999, res = -1;
    struct Node *p = head1, *q = head2;
    while (p)
    {
        q = head2;
        while (q)
        {
            if (p->data == q->data && p->data <= min)
            {
                res = p->data;
            }
            q = q->next;
        }
        if (res < min)
            min = res;

        p = p->next;
    }
    return min;
}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    Create(&head1);
    Create(&head2);
    printf("List 1 : ");
    Display(head1);
    printf("List 2 : ");
    Display(head2);
    printf("\nLowest Common Element is %d\n", LowestCommonElement(head1, head2));
    free(head1);
    free(head2);
    return 0;
}