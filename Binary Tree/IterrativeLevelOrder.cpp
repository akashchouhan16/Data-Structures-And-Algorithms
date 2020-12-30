#include <cstdlib>
#include <iostream>
#include <queue>
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
// LevelOrder - Iterative Traversal.
void LevelOrder(Tree *root)
{
    queue<Tree *> q;
    if (!root)
        return;
    cout << root->data << " ";
    q.push(root);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        if (temp->left)
        {
            cout << temp->left->data << " ";
            q.push(temp->left);
        }
        if (temp->right)
        {
            cout << temp->right->data << " ";
            q.push(temp->right);
        }
    }
    return;
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!";
    cout << "\nLevelOrder Traversal : ";
    LevelOrder(root);
    delete root;
    return 0;
}