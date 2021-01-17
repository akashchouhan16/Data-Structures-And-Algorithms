#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int *data;
} Stack;

void push(Stack *s, int x, int cap)
{
    if (s->top == cap)
    {
        printf("Stack Oveflow.\n");
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
        return;
    }
}
int pop(Stack *s, int cap)
{
    int res = -1;
    if (s->top == -1)
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        res = s->data[s->top];
        s->top--;
    }
    return res;
}
void DisplayStack(Stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->data[i]);
    }
    printf("\nDisplayCalled.\n");
}
Stack *copyStackfunc(Stack *s1, Stack *s2, int cap)
{
    Stack *temp;
    temp->top = -1;
    temp->data = (int *)malloc(sizeof(int) * cap); // Creating a temporary Stack.
    while (s1->top != -1)
    {
        push(temp, pop(s1, cap), cap);
    }
    printf("\nTemp Stack is :\n");
    DisplayStack(temp);
    while (s2->top != cap)
    {
        push(s2, pop(temp, cap), cap);
    }
    DisplayStack(s2);
    return s2;
}

int main()
{
    int choice = 0, cap = 0;
    Stack s1;
    printf("Enter Stack Capacity : ");
    scanf("%d", &cap);
    s1.data = (int *)malloc(sizeof(int) * cap); //Dynamic Stack Creation.
    s1.top = -1;
    printf("Enter 1 to push\nEnter 2 pop\nEnter 3 to Copy Stack\nEnter 0 to Display and Exist.\n");
    do
    {
        printf("Enter Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int data;
            printf("Enter Data : ");
            scanf("%d", &data);
            push(&s1, data, cap);
            DisplayStack(&s1);
        }
        else if (choice == 2)
        {
            int res = pop(&s1, cap);
            if (res != -1)
                printf("\n%d Removed from Stack.\n", res);
            DisplayStack(&s1);
        }
        else if (choice == 3)
        {
            Stack *s2;
            s2->top = -1;
            s2->data = (int *)malloc(sizeof(int) * cap); //new Stack.
            copyStackfunc(&s1, s2, cap);
            // printf("New Stack : \n");
            // DisplayStack(s2);
        }
        else if (choice == 0)
        {
            DisplayStack(&s1);
            break;
        }
    } while (choice != 0);

    free(s1.data);
}