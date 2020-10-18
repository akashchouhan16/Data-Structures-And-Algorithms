#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *Create() //Recurssive Approach.
{
    struct Node *temp = NULL;
    int x;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Unable to Create Node.\n");
        return NULL;
    }
    printf("Enter the Node value : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    temp->data = x;
    printf("Enter Left Child of %d ", x);
    temp->left = Create();
    printf("Enter the right Child of %d ", x);
    temp->right = Create();

    return temp;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->left);
        printf("%d, ", p->data);
        Inorder(p->right);
    }
    return;
}
int main()
{
    struct Node *root1 = NULL;
    root1 = Create();
    printf("In-Order : ");
    Inorder(root1);
    free(root1);
    return 0;
}