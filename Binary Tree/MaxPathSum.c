#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
struct Node *CreateBinaryTree()
{
    int data;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Heap FULL!\n");
        return NULL;
    }
    printf("Enter data : ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    temp->data = data;
    printf("For Left child of %d, ", temp->data);
    temp->left = CreateBinaryTree();
    printf("For Right Child of %d, ", temp->data);
    temp->right = CreateBinaryTree();

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
    else
        return;
}
int findMaxUtil(struct Node *root, int *res)
{
    if (!root)
        return 0;
    int l = findMaxUtil(root->left, res);
    int r = findMaxUtil(root->right, res);
    int max_single = max(max(l, r) + root->data, root->data);
    int max_top = max(max_single, l + r + root->data);
    *res = max(*res, max_top);
    return max_single;
}
int FindMaxpathSum(struct Node *root)
{
    int res = INT_MIN;
    res = findMaxUtil(root, &res);
    return res;
}

int main()
{
    struct Node *root = NULL;
    int ch, data;
    printf("Enter 1 to Insert to Binary tree\nEnter 2 to Inorder traverse\nEnter 3 to Find Max Path Sum\nzenter 0 to exit().\n");
    do
    {
        printf("Enter choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            root = CreateBinaryTree();
        }
        else if (ch == 2)
        {
            printf("InOrder traversal : ");
            Inorder(root);
        }
        else if (ch == 3)
        {
            printf("Max Path Sum = %d\n", FindMaxpathSum(root));
        }
        else
        {
            if (ch != 0)
                printf("Invalid Choice!\n");
            else
                break;
        }

    } while (ch != 0);
    free(root);
    return 0;
}