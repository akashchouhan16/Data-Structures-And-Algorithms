#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *root = NULL;

void Insert(int val)
{
    struct Node *temp = NULL, *r = NULL, *p = root;
    if (root == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = val;
        temp->left = temp->right = NULL;
        root = temp;
        return;
    }
    while (p)
    {
        r = p;
        if (val == p->data)
            return;
        if (val < p->data)
            p = p->left;
        else if (val > p->data)
            p = p->right;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    if (temp->data < r->data)
        r->left = temp;
    else if (temp->data > r->data)
        r->right = temp;
    return;
}

void InOrder(struct Node *p)
{
    if (p)
    {
        InOrder(p->left);
        printf("%d,", p->data);
        InOrder(p->right);
    }
    return;
}
int Utility(struct Node *p, int min, int max)
{
    if (!p)
        return 1;
    if (p->data < min || p->data > max)
        return 0;
    return Utility(p->left, min, p->data - 1) && Utility(p->right, p->data + 1, max);
}
int isBST(struct Node *root)
{
    return Utility(root, INT_MIN, INT_MAX);
}

int main()
{
    int ch, data;
    printf("Enter 1 to Insert to BST\nEnter 2 to Inorder Traverse\nEnter 3 to Check for BST\nEnter 0 to exit\n");
    do
    {
        printf("Enter Choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter data : ");
            scanf("%d", &data);
            Insert(data);
        }
        else if (ch == 2)
        {
            printf("In-Order : ");
            InOrder(root);
            printf("\n");
        }
        else if (ch == 3)
        {
            if (isBST(root) == 1)
            {
                printf("Tree is a Binary Search tree\n");
            }
            else
                printf("It is not a Binary Search Tree\n");
        }
        else
        {
            if (ch != 0)
                printf("Invalid Choice\n");
            else
                break;
        }
    } while (ch != 0);
    printf("\nCode Terminated!\n");
    free(root);
    return 0;
}