//To Check if the First and the second Half of the SLL are matching.
/*
    Eg : 12->99->35->12->99 : True
         1->3->5->1->4 : False
*/
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
bool checkHalves(struct Node *head)
{
    struct Node *p = head, *q = head;
    struct Node *temp;
    while (p && p->next)
    {
        q = q->next;
        p = p->next->next;
    }
    temp = q; //at middle Node.
    printf("Middle Node : %d\n", temp->data);
    p = head;
    // temp = temp->next;
    while (temp)
    {
        if (p->data != temp->data)
            return false;
        temp = temp->next;
        p = p->next;
    }
    return true;
}
int main()
{
    struct Node *head = NULL;
    Create(&head);
    printf("List : ");
    Display(head);
    printf("\nMatching Halves : %s", checkHalves(head) ? "Matching!" : "Not Matching!");
    free(head);
    return 0;
}