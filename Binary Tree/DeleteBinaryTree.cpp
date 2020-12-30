#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Tree;

Tree *CreateBinaryTree()
{
    Tree *temp = new Tree();
    int data;
    cout << "Enter Data : ";
    cin >> data;
    if (data == -1)
        return NULL;
    temp->data = data;
    cout << "For Left Child of " << temp->data << ", ";
    temp->left = CreateBinaryTree();
    cout << "For Right Child of " << temp->data << ", ";
    temp->right = CreateBinaryTree();
    return temp;
}
void deleteAll(Tree **root)
{
    if (!*root)
    {
        cout << "NULL Tree.. nothing to delete\n";
        return;
    }
    queue<Tree *> q;
    q.push(*root);
    while (!q.empty())
    {
        Tree *node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        cout << "\nDeleted " << node->data << "..";
        free(node);
    }
    *root = NULL;
    return;
}
void Inorder(Tree *root)
{
    Tree *temp = root;
    stack<Tree *> s;
    if (!root)
    {
        cout << "Empty Tree..\n";
        return;
    }
    while (temp || !s.empty())
    {
        if (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    return;
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    deleteAll(&root);
    cout << "\nInorder traversal : ";
    Inorder(root); //Just to reassure.
    free(root);
    return 0;
}