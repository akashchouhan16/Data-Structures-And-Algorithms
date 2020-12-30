// ReferGFG for Flip Operation.
#include <cstdlib>
#include <iostream>
#include <stack>
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
    cout << "Enter the Data : ";
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
Tree *FlipTheTree(Tree *root)
{
    if (!root)
        return root;
    if (!root->left && !root->right)
        return root;
    Tree *flipped = FlipTheTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = NULL;

    return flipped;
}

int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    root = FlipTheTree(root);
    cout << "Tree Flipped...\nNew Inorder Traversal : ";
    Inorder(root);
    free(root);
    return 0;
}