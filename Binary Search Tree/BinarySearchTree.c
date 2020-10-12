//Operations on Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *root = NULL;
void Insert(int x)
{
    struct Node *temp = NULL, *r = NULL, *p = root;
    if (root == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = x;
        temp->left = temp->right = NULL;
        root = temp;
        return;
    }
    while (p != NULL)
    {
        r = p;
        if (x == p->data)
            return; //to prevent Duplicacy in BST.
        else if (x < p->data)
            p = p->left;
        else if (x > p->data)
            p = p->right;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = x;
    if (temp->data < r->data)
        r->left = temp;
    else if (temp->data > r->data)
        r->right = temp;
    return;
}
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *temp = NULL;
    if (p == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->left = temp->right = NULL;
        temp->data = key;
        return temp;
    }
    if (key < p->data)
    {
        p->left = RInsert(p->left, key);
    }
    else if (key > p->data)
        p->right = RInsert(p->right, key);
    return p;
}
void InOrder(struct Node *p)
{
    if (p)
    {
        InOrder(p->left);
        printf("%d, ", p->data);
        InOrder(p->right);
    }
    return;
}
int getTreeHeight(struct Node *p)
{
    int x = 0, y = 0;
    while (p)
    {
        x = getTreeHeight(p->left);
        y = getTreeHeight(p->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}
int main()
{
    printf("Enter 1 to Insert to BST\nEnter 2 to Display current BST\nEnter 3 to get the BST Height\nEnter 0 to exit(0)\n");
    int ch = 0;
    // root = RInsert(root, 8);
    do
    {
        printf("Enter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int key;
            if (!root)
                printf("Enter Root Node value : ");
            else
                printf("Enter node value : ");
            scanf("%d", &key);
            Insert(key);
            // RInsert(root, key);
        }
        else if (ch == 2)
        {
            printf("Inorder : ");
            InOrder(root);
        }
        else if (ch == 3)
        {
            printf("Height of Binary Search tree : %d\n", getTreeHeight(root));
        }
        else
            break;
    } while (ch != 0);
    free(root);
    printf("Code Terminated!\n");
    return 0;
}