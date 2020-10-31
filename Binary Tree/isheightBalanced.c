//To check if the Binary Tree has balanced height. Similar Concept is used in AVl trees.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *Create()
{
    struct Node *temp = NULL;
    int data;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Heap Full\n");
        return NULL;
    }
    printf("Enter Node value : ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;

    temp->data = data;
    printf("For left child of %d, ", data);
    temp->left = Create();
    printf("For Right child of %d  ", data);
    temp->right = Create();

    return temp;
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
int getHeight(struct Node *p)
{
    int x = 0, y = 0;
    if (p)
    {
        x = getHeight(p->left);
        y = getHeight(p->right);
        return (x > y) ? x + 1 : y + 1;
    }
    return 0;
}
int isBalanced(struct Node *root)
{
    int leftheight, rightheight;
    if (root == NULL)
        return 1;

    leftheight = getHeight(root->left);
    rightheight = getHeight(root->right);
    if (abs(leftheight - rightheight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}
int main()
{
    struct Node *root = NULL;
    root = Create();
    printf("InOrder traversal : ");
    InOrder(root);
    printf("\nTree Height : %d\n", getHeight(root));
    printf("\nIs the Binary Tree Height Balanced? %s\n", ((isBalanced(root)) ? "YES" : "NO"));

    free(root);
    return 0;
}