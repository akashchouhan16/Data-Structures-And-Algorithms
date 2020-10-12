#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Ndoe *right;
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
int main()
{
    printf("Enter 1 to Insert to BST\nEnter 2 to Display current BST\nEnter 3 to Search in BST\nEnter 0 to exit(0)\n");
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
            struct Node *p = Search(root, key);
            if (p)
            {
                printf("Node with %d Found!\n", p->data);
            }
            else
                printf("Node Not Found in the BST.\n");
        }
        else
            break;
    } while (ch != 0);
    free(root);
    printf("Code Terminated!\n");
    return 0;
}