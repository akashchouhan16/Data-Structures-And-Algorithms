// #include <bits/stdc++.h>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *CreateBinaryTree()
{
    int data;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    printf("Enter Data : ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    temp->data = data;
    printf("Enter the Left Child of %d, ", temp->data);
    temp->left = CreateBinaryTree();
    printf("Enter the Right Child of %d, ", temp->data);
    temp->right = CreateBinaryTree();
    return temp;
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->left);
        printf("%d,", p->data);
        Inorder(p->right);
    }
    else
        return;
}
void TopView(struct Node *root)
{
    if (!root)
        return;

    unordered_map<int, int> m;
    queue<pair<struct Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<struct Node *, int> p = q.front();
        struct Node *n = p.first;
        int val = p.second;
        q.pop();
        if (m.find(val) == m.end())
        {
            m[val] = n->data;
            printf("%d, ", n->data);
        }
        if (n->left != NULL)
        {
            q.push(make_pair(n->left, val - 1));
        }
        if (n->right != NULL)
        {
            q.push(make_pair(n->right, val + 1));
        }
    }
}
int main()
{
    struct Node *root = NULL;
    int ch, data;
    printf("Enter 1 to Create\nEnter 2 to Inorder Traverse\nEnter 3 to Find Top View\nEnter 0 to exit().\n");
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
            printf("Inorder Traversal : ");
            Inorder(root);
        }
        else if (ch == 3)
        {
            printf("Top View : ");
            TopView(root);
        }
        else
        {
            if (ch != 0)
                printf("Invalid Choice!");
            else
                printf("Code Terminated!\n");
        }
    } while (ch != 0);
    free(root);
    return 0;
}