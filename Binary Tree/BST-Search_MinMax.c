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
struct Node *Search(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        if (key == p->data)
            return p;
        else if (key < p->data)
            return Search(p->left, key);
        else
            return Search(p->right, key);
    }
    return NULL;
}
struct Node *ISearch(struct Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
            return p;
        else if (p->data > key)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}
int MaxinBST(struct Node *root)
{
    while (root && root->right)
    {
        root = root->right;
    }
    return root->data;
}
int MininBST(struct Node *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root->data;
}
int IMax(struct Node *root)
{
    if (root->right == NULL)
        return root->data;
    else
        IMax(root->right);
}
int IMin(struct Node *root)
{
    if (root->left == NULL)
        return root->data;
    else
        IMin(root->left);
}
int main()
{
    printf("Enter 1 to Insert to BST\nEnter 2 to Display current BST\nEnter 3 to Search in BST\nEnter 4 to get MAX element\nEnter 5 to get Min\nEnter 0 to exit(0)\n");
    int ch = 0, key;
    do
    {
        printf("Enter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {

            printf("Enter node value : ");
            scanf("%d", &key);
            Insert(key);
        }
        else if (ch == 2)
        {
            printf("Inorder : ");
            InOrder(root);
        }
        else if (ch == 3)
        {
            printf("Enter the Search query : \n");
            scanf("%d", &key);
            struct Node *p = ISearch(root, key);
            if (p)
            {
                printf("Node with %d Found!\n", p->data);
            }
            else
                printf("Node Not Found in the BST.\n");
        }
        else if (ch == 4)
        {
            printf("Max Element in BST  : %d\n", MaxinBST(root));
        }
        else if (ch == 5)
        {
            printf("Min Element in BST : %d\n", MininBST(root));
        }
        else
            break;
    } while (ch != 0);

    printf("Iterative Ans : %d(MIN), %d(MAX)\n", IMin(root), IMax(root));

    free(root);
    printf("Code Terminated!\n");
    return 0;
}