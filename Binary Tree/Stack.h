#ifndef Stack_h
#define Stack_h
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Stack
{
    int top;
    int size;
    struct Node **data;
};
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
void Initialize(struct Stack *s, int cap)
{
    s->top = -1;
    s->size = cap;
    s->data = (struct Node **)malloc(cap * sizeof(struct Node *));
    if (s->data == NULL)
    {
        printf("Unable to Create Stack!\n");
    }
}
void push(struct Stack *s, struct Node *p)
{
    if (s->top == s->size - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    else
    {
        s->top++;
        s->data[s->top] = p;
    }
}
struct Node *pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack UnderFlow\n");
        return NULL;
    }
    else
    {
        struct Node *res = s->data[s->top];
        s->top--;
        return res;
    }
}
#endif
