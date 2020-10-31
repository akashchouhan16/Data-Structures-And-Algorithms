// TASK : 1. insert() to create BST. 2. Perform Search Operation by using bool func. 3. Deletion by Value in the same BST.
// This Program is just to Recap Binary Search Tree basic Operations. 14/10/20.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
        temp->left = temp->right = NULL;
        temp->data = val;
        root = temp;
        return;
    }
    while (p)
    {
        r = p;
        if (val < p->data)
            p = p->left;
        else if (val > p->data)
            p = p->right;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    if (temp->data > r->data)
        r->right = temp;
    else
        r->left = temp;
    return;
}
void Display(struct Node *p)
{
    if (p)
    {
        Display(p->left);
        printf("%d,", p->data);
        Display(p->right);
    }
    return;
}
bool RecurssiveSearch(struct Node *p, int key)
{
    if (!p)
        return false;
    if (p)
    {
        if (key == p->data)
            return true;
        else if (key < p->data)
            RecurssiveSearch(p->left, key);
        else if (key > p->data)
            RecurssiveSearch(p->right, key);
    }
    else
        return false;
}
// ** UTILITY FUNCTIONS for Deletion().
int getTreeHeight(struct Node *p)
{
    int x = 0, y = 0;
    if (!p)
        return 0;
    else
    {
        x = getTreeHeight(p->left);
        y = getTreeHeight(p->right);
        return (x > y) ? x + 1 : y + 1;
    }
}
struct Node *InOrderPredecessor(struct Node *p)
{
    while (p && p->right)
        p = p->right;
    return (p);
}
struct Node *InOrderSuccessor(struct Node *p)
{
    while (p && p->left)
        p = p->left;
    return (p);
}

struct Node *DeleteInBST(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->left == NULL && p->right == NULL)
    {
        if (root == p)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->left = DeleteInBST(p->left, key);
    else if (key > p->data)
        p->right = DeleteInBST(p->right, key);
    else
    {
        if (getTreeHeight(p->left) > getTreeHeight(p->right))
        {
            q = InOrderPredecessor(p->left);
            p->data = q->data;
            p->left = DeleteInBST(p->left, q->data);
        }
        else if (getTreeHeight(p->left) < getTreeHeight(p->right))
        {
            q = InOrderSuccessor(p->right);
            p->data = q->data;
            p->right = DeleteInBST(p->right, q->data);
        }
    }
    return p;
}
void UtilityDisplay(struct Node *root, int space)
{
    if (root == NULL)
        return;
    space += 10;

    UtilityDisplay(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d", root->data);

    UtilityDisplay(root->left, space);
}
void Display2D(struct Node *root)
{
    UtilityDisplay(root, 0);
}
int main()
{
    int ch, key;
    printf("Enter 1 to Insert to BST\nEnter 2 to Display\nEnter 3 to Search\nEnter 4 to Delete from BST\nEnter 0 to exit(0)\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {

            if (!root)
            {
                printf("Enter root node value : ");
                scanf("%d", &key);
                Insert(key);
            }
            else
            {
                printf("Enter node value : ");
                scanf("%d", &key);
                Insert(key);
            }
        }
        else if (ch == 2)
        {
            printf("In-Order Traversal : ");
            Display(root);
            printf("\nTree : \n");
            Display2D(root);
        }
        else if (ch == 3)
        {
            printf("Enter Search Key : ");
            scanf("%d", &key);
            if (RecurssiveSearch(root, key))
                printf("Element %d Found in the BST.\n", key);
            else
                printf("Element Not Found in the BST.\n");
        }
        else if (ch == 4)
        {
            printf("Enter val to Delete : ");
            scanf("%d", &key);
            DeleteInBST(root, key);
        }
        else
        {
            if (ch != 0)
                printf("Invalid Choice.\n");
        }
    } while (ch != 0);
    free(root);
    printf("Code Terminated.\n");
    return 0;
}