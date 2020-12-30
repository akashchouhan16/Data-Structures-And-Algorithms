#include <cstdlib>
#include <stack>
#include <iostream>
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
    cout << "For Left child of " << temp->data << ", ";
    temp->left = CreateBinaryTree();
    cout << "For Right Child of " << temp->data << ", ";
    temp->right = CreateBinaryTree();
    return temp;
}
void Inorder(Tree *root)
{
    if (root)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
    else
        return;
}
void SpiralOrder(Tree *root)
{
    if (!root)
        return;
    stack<Tree *> s1;
    stack<Tree *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Tree *temp = s1.top();
            cout << temp->data << ",";
            s1.pop();
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
        while (!s2.empty())
        {
            Tree *temp = s2.top();
            s2.pop();
            cout << temp->data << ",";
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
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
    cout << "\nSpiral Order Traversal : ";
    SpiralOrder(root);
    free(root);
    return 0;
}