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
void LeafNodes(struct Node *p)
{
    if (p)
    {
        if (!p->left && !p->right)
            printf("%d,", p->data);
        LeafNodes(p->left);
        LeafNodes(p->right);
    }
    return;
}
int main()
{
    int ch;
    printf("Enter 1 to Insert in BST\nEnter 2 to Display Leaf Nodes \nEnter 3 to InOrder Tranverse \nEnter 0 to exit(0)\n");
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
            printf("Leaf Nodes are : ");
            LeafNodes(root);
            printf("\n");
        }
        else if (ch == 3)
        {
            printf("In-Order : ");
            InOrder(root);
            printf("\n");
        }
        else
            break;
    } while (ch != 0);
    printf("Code Terminated!\n");
    free(root);
    return 0;
}