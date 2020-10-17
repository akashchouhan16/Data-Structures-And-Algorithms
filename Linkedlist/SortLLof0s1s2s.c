#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        srand(time(0));
        // temp->data = rand() % 3;
        printf("Enter data : "); // 0,1 or 2
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
        printf("Node Created! Create another?(1/0) : ");
        scanf("%d", &ch);
    } while (ch != 0);
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
    {
        printf("NULL\n");
        return;
    }
}

void Sort(struct Node **head)
{
    struct Node *p = *head, *tail = *head;
    int count[3] = {0, 0, 0};
    while (tail != NULL)
    {
        count[tail->data]++;
        tail = tail->next;
    }
    int i = 0;
    while (p != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            p->data = i;
            --count[i];
            p = p->next;
        }
    }
}
int main()
{
    struct Node *list1 = NULL;
    Create(&list1);
    Display(list1);
    Sort(&list1);
    Display(list1);
    free(list1);
    return 0;
}