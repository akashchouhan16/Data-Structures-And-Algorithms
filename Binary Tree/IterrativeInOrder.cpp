#include <cstdlib>
#include <iostream>
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
// InOrder - Iterative Traversal.
void InOrder(Tree *root)
{
    stack<Tree *> St;
    Tree *temp = root, *p = root;
    while (temp || !St.empty())
    {
        if (temp)
        {
            St.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = St.top();
            cout << temp->data << " ";
            St.pop();
            temp = temp->right;
        }
    }
    return;
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!";
    cout << "\nInOrder Traversal : ";
    InOrder(root);
    delete root;
    return 0;
}