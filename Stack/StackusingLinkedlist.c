#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(struct Node *s)
{
    int x;
    printf("Enter data : ");
    scanf("%d", &x);
    struct Node *temp, *p = top;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = x;
    if (top == 0)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

int pop(struct Node *s)
{
    int x = -1;
    struct Node *temp = top;
    if (top == NULL)
    {
        printf("Stack undeflow.\n");
        return x;
    }
    else
    {
        top = top->next;
        x = temp->data;
        free(temp);
        return x;
    }
}
void Display(struct Node *s)
{
    printf("Current Stack \n");
    while (s)
    {
        printf("%d\n", s->data);
        s = s->next;
    }
}

int main()
{
    int ch;
    do
    {
        printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to display\nEnter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            push(top);
            Display(top);
        }
        else if (ch == 2)
        {
            printf("%d popped.\n", pop(top));
            Display(top);
        }
        else
        {
            Display(top);
        }
    } while (ch != 0);

    free(top);
    return 0;
}