#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head = NULL, *tail = NULL;

void Create()
{
    struct Node *temp, *p;
    int ch;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->prev = NULL;
        printf("Enter the Data : ");
        scanf("%d", &temp->data);

        if (head == NULL)
        {
            head = tail = p = temp; //tail added later, if you're using tail then no need of *p.
        }
        else
        {
            p->next = temp;
            temp->prev = p;
            p = temp;
            tail = p;
        }
        printf("Do you want to Create a new Node?(1/0) ");
        scanf("%d", &ch);
    } while (ch == 1);
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d<=>", p->data);
        p = p->next;
    }
    printf("NULL");
}
void ReverseDisplay(struct Node *p)
{
    if (p != NULL)
    {
        ReverseDisplay(p->next);
        printf("%d<=>", p->data);
    }
    else
        printf("NULL<=>");
}
void InsertAtfirst()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter the Value : ");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

int FindSecondmax(struct Node *p)
{
    int max = INT_MIN;
    int secondmax = -1;
    while (p != NULL)
    {
        if (p->data > max)
        {
            secondmax = max;
            max = p->data;
        }
        if (p->data > secondmax && p->data < max)
            secondmax = p->data;
        p = p->next;
    }
    return secondmax;
}
int isLoop(struct Node *p) //to Detect Loop (test).
{
    struct Node *q = head;
    do
    {
        p = p->next;
        q = q->next;
        if (p)
            p = p->next;
    } while (p && q && p != q);

    return (p == q) ? 1 : 0;
}
int main()
{
    Create();
    Display(head);
    printf("\n");
    ReverseDisplay(head);
    printf("\nThe Second Greatest Number is %d\n Value of Last Node is %d\n", FindSecondmax(head), tail->data);
    InsertAtfirst();
    Display(head);
    return 0;
    free(head);
}
