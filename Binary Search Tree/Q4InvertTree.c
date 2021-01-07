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

void mirrorTree(struct Node *root)
{
    if (root == NULL)
        return;
    else
    {
        struct Node *temp;
        mirrorTree(root->left);
        mirrorTree(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
}
int main()
{
    struct Node *root = NULL;
    root = Create();
    printf("In-Order : ");
    InOrder(root);
    mirrorTree(root);
    printf("Inverted In-Order : ");
    InOrder(root);
    free(root);
    return 0;
}