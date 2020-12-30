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
    cout << "Enter the Data : ";
    cin >> data;
    if (data == -1)
        return nullptr;
    temp->data = data;
    cout << "For Left Child of " << temp->data << ", ";
    temp->left = CreateBinaryTree();
    cout << "For Right Child of " << temp->data << ", ";
    temp->right = CreateBinaryTree();
    return temp;
}
void Inorder(Tree *root)
{
    if (!root)
        return;
    Tree *temp = root;
    stack<Tree *> st;
    while (temp || !st.empty())
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    return;
}
void InvertBinaryTree(Tree *root)
{
    if (!root)
        return;
    else
    {
        Tree *temp;
        InvertBinaryTree(root->left);
        InvertBinaryTree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binart Tree Created!\n";
    cout << "InOrder Traversal : ";
    Inorder(root);
    InvertBinaryTree(root);
    cout << "Inorder Of Inverted Binary Tree : ";
    Inorder(root);
    free(root);
    return 0;
}