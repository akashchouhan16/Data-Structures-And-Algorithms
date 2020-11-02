#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *CreateTree()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    int data;
    if (!temp)
    {
        printf("Heap Full\n");
        return NULL;
    }
    printf("Enter Data : ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    temp->data = data;
    printf("For Left Child of %d,  ", data);
    temp->left = CreateTree();
    printf("For Right Child of %d,  ", data);
    temp->right = CreateTree();

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
void DeleteEntireTree(struct Node *root)
{
    if (root == NULL)
        return;
    struct Queue Q;
    create(&Q, 20);
    enqueue(&Q, root);
    while (!isEmpty(Q))
    {
        struct Node *temp = dequeue(&Q);

        if (temp->left)
            enqueue(&Q, temp->left);
        if (temp->right)
            enqueue(&Q, temp->right);

        free(temp);
    }
    free(Q.Q);
    printf("\nBinary Tree Delete!\n");
    root = NULL;
    return;
}
int main()
{
    struct Node *root = NULL;
    root = CreateTree();
    printf("In-Order traversal : ");
    Inorder(root);
    DeleteEntireTree(root);

    Inorder(root);
    free(root);
    return 0;
}