#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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
    printf("Enter data : ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    temp->data = data;
    printf("For Left child of %d,  ", data);
    temp->left = Create();
    printf("For Right Child of %d,  ", data);
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
int max(int a, int b)
{
    return (a > b) ? a : b;
}
//Solution :
int diameter(struct Node *root)
{
    if (root == NULL)
        return 0;

    int left = getHeight(root->left);
    int right = getHeight(root->right);
    int ldia = diameter(root->left);
    int rdia = diameter(root->right);

    return max((left + right + 1), max(ldia, rdia));
}

int main()
{
    struct Node *root = NULL;
    root = Create();
    printf("In-Order traversal : ");
    InOrder(root);

    printf("\nTree Height : %d\n", getHeight(root));
    printf("\nDiameter of the Tree : %d\n", diameter(root));
    free(root);
    return 0;
}