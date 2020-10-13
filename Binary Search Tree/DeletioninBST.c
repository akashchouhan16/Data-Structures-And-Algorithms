#include <stdio.h>
#include <stdlib.h>

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
        r = p; //tail pointer.
        if (val == p->data)
            return; //to prevent Duplicacy in BST.
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
//Utility Functions for Deletion in BST.
int getHeight(struct Node *p)
{
    int x = 0, y = 0;
    if (!p)
        return 0;
    else
    {
        x = getHeight(p->left);
        y = getHeight(p->right);
        return (x > y) ? x + 1 : y + 1;
    }
}
struct Node *InorderPredecessor(struct Node *p)
{
    while (p && p->right)
        p = p->right;
    return p;
}
struct Node *InorderSuccessor(struct Node *p)
{
    while (p && p->left)
        p = p->left;
    return p;
}
//Deletion of Node in BST;
struct Node *deleteNode(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->left = deleteNode(p->left, key);
    else if (key > p->data)
        p->right = deleteNode(p->right, key);
    else
    {
        if (getHeight(p->left) > getHeight(p->right))
        {
            q = InorderPredecessor(p->left);
            p->data = q->data;
            p->left = deleteNode(p->left, q->data);
        }
        else if (getHeight(p->left) < getHeight(p->right))
        {
            q = InorderSuccessor(p->right);
            p->data = q->data;
            p->right = deleteNode(p->right, q->data);
        }
    }
    return p;
}
int main()
{
    int ch;
    printf("Enter 1 to Insert in BST\nEnter 2 to Delete in BST\nEnter 3 to InOrder Tranverse the BST\nEntr 0 to exit(0)\n");
    do
    {
        printf("Enter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int val;
            printf("Enter Node value : ");
            scanf("%d", &val);
            Insert(val);
        }
        else if (ch == 2)
        {
            int key;
            printf("Enter key data to delete : ");
            scanf("%d", &key);
            deleteNode(root, key);
        }
        else if (ch == 3)
        {
            printf("In-Order : ");
            InOrder(root);
            printf("\n");
        }
        else
            exit(0);
    } while (ch != 0);
    free(root);
    return 0;
}