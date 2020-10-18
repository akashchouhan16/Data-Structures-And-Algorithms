#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
struct Node *root = NULL;
void Treecreate() //Non-recursive Approach
{
    struct Node *p, *temp;
    int x;
    struct Queue q;
    create(&q, 13);

    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->left = temp;
            enqueue(&q, temp);
        }
        printf("enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->right = temp;
            enqueue(&q, temp);
        }
    }
}
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->left);
        printf("%d ", p->data);
        Inorder(p->right);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->left);
        Postorder(p->right);
        printf("%d ", p->data);
    }
}

void LevelOrder(struct Node *p)
{
    struct Queue q1;
    create(&q1, 13);
    printf("%d ", p->data);
    enqueue(&q1, p);
    while (!isEmpty(q1))
    {
        p = dequeue(&q1);
        if (p->left)
        {
            printf("%d ", p->left->data);
            enqueue(&q1, p->left);
        }
        if (p->right)
        {
            printf("%d ", p->right->data);
            enqueue(&q1, p->right);
        }
    }
    free(q1.Q);
    return;
}
int Count(struct Node *p)
{
    int x, y;
    if (p)
    {
        x = Count(p->left);
        y = Count(p->right);
        return (x + y + 1);
    }
    return 0;
}
int Countnode(struct Node *root)
{
    if (root)
        return (Count(root->left) + Count(root->right) + 1);
    return 0;
}
int getTreeHeight(struct Node *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = getTreeHeight(root->left);
        y = getTreeHeight(root->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}
int main()
{
    int ch = 0;
    Treecreate();
    printf("Tree Created. (Number of Nodes = %d)\n", Countnode(root));
    printf("\nHeight of the Tree Created : %d\n", getTreeHeight(root));
    printf("Enter 1 for PreOrder\nEnter 2 for InOrder\nEnter 3 for PostOrder\nEnter 4 for LevelOrder\nEnter 0 to exit(0)\n");
    do
    {
        printf("Enter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("PreOrder : ");
            Preorder(root);
        }
        else if (ch == 2)
        {
            printf("InOrder : ");
            Inorder(root);
        }
        else if (ch == 3)
        {
            printf("PostOrder : ");
            Postorder(root);
        }
        else if (ch == 4)
        {
            printf("LevelOrder : ");
            LevelOrder(root);
        }
        else
        {
            printf("\nCode Terminated!\n");
        }
    } while (ch != 0);
    free(root);
    return 0;
}