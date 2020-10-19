#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
struct Node *Create()
{
    int x;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Node value : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    temp->data = x;
    printf("Enter the left Child of %d ", x);
    temp->left = Create();
    printf("Enter the Right Child of %d ", x);
    temp->right = Create();
    return temp;
}
void PreOrder(struct Node *temp)
{
    struct Stack st;
    Initialize(&st, 10);
    while (temp || !isEmpty(&st))
    {
        if (temp)
        {
            printf("%d, ", temp->data);
            push(&st, temp);
            temp = temp->left;
        }
        else
        {
            temp = pop(&st);
            temp = temp->right;
        }
    }
    free(st.data);
}
void InOrder(struct Node *temp)
{
    struct Stack st2;
    Initialize(&st2, 20);
    while (temp || !isEmpty(&st2))
    {
        if (temp)
        {
            push(&st2, temp);
            temp = temp->left;
        }
        else
        {
            temp = pop(&st2);
            printf("%d, ", temp->data);
            temp = temp->right;
        }
    }
    free(st2.data);
}
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    else
    {
        struct Stack s1;
        Initialize(&s1, 30);
        struct Stack s2;
        Initialize(&s2, 30);
        push(&s1, root);
        struct Node *temp = NULL;

        while (!isEmpty(&s1))
        {
            temp = pop(&s1);
            push(&s2, temp);
            if (temp->left)
                push(&s1, temp->left);
            if (temp->right)
                push(&s1, temp->right);
        }

        while (!isEmpty(&s2))
        {
            temp = pop(&s2);
            printf("%d, ", temp->data);
        }
        free(s2.data);
        free(s1.data);
    }
}

void InOrderRecurrsive(struct Node *root)
{
    if (root)
    {
        InOrderRecurrsive(root->left);
        printf("%d, ", root->data);
        InOrderRecurrsive(root->right);
    }
    return;
}
void preOrderRecurssive(struct Node *p)
{
    if (p)
    {
        printf("%d, ", p->data);
        preOrderRecurssive(p->left);
        preOrderRecurssive(p->right);
    }
    return;
}
void PostOrderRecurssive(struct Node *p)
{
    if (p)
    {
        PostOrderRecurssive(p->left);
        PostOrderRecurssive(p->right);
        printf("%d, ", p->data);
    }
    return;
}
int main()
{
    struct Node *root = NULL;
    root = Create();
    int choice;
    printf("Enter 1 for Pre-Order Traversal\nEnter 2 for In-Order Traversal\nEnter 3 for Post-Order Traversal\nEnter 0 to exit\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Pre-Order : ");
            PreOrder(root);
        }
        else if (choice == 2)
        {
            printf("\nIn-Order : ");
            InOrder(root);
        }
        else if (choice == 3)
        {
            printf("\nPost-Order : ");
            // PostOrderRecurssive(root);
            postOrder(root);
        }
    } while (choice != 0);

    printf("\nRecurssive traversals \n");
    printf("Pre-Order : ");
    preOrderRecurssive(root);
    printf("\nIn-Order : ");
    InOrderRecurrsive(root);
    printf("\nPost-Order : ");
    PostOrderRecurssive(root);

    free(root);
    return 0;
}