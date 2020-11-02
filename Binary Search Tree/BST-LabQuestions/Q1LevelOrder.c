
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
void LevelOrder(struct Node *root)
{
    struct Queue Q;
    create(&Q, 10);
    printf("%d,", root->data);
    enqueue(&Q, root);
    while (!isEmpty(Q))
    {
        struct Node *p = dequeue(&Q);
        if (p->left)
        {
            printf("%d,", p->left->data);
            enqueue(&Q, p->left);
        }
        if (p->right)
        {
            printf("%d,", p->right->data);
            enqueue(&Q, p->right);
        }
    }
    return;
}
int main()
{
    struct Node *root = NULL;
    root = CreateTree();
    printf("Level Order : ");
    LevelOrder(root);
    free(root);
    return 0;
}