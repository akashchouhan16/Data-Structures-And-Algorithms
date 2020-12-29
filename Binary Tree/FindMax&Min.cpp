// To Find the Maximum and Minimum element in a Binary tree.
#include <cstdlib>
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
    Tree *temp = NULL;
    int data;
    temp = new Tree();
    cout << "Enter Data : ";
    cin >> data;
    if (data == -1)
        return NULL;
    temp->data = data;
    cout << "For Left Child of " << temp->data << " ";
    temp->left = CreateBinaryTree();
    cout << "For Right CHild of " << temp->data << " ";
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
void PreOrder(Tree *root)
{
    if (root)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    else
        return;
}
int getMax(Tree *root)
{
    if (!root)
        return INT_MIN;
    int res = root->data;
    int l = getMax(root->left);
    int r = getMax(root->right);
    if (l > res)
        res = l;
    if (r > res)
        res = r;
    return res;
}
int getMin(Tree *root)
{
    if (!root)
        return INT_MAX;
    int res = root->data;
    int l = getMin(root->left);
    int r = getMin(root->right);
    if (l < res)
        res = l;
    if (r < res)
        res = r;
    return res;
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder traversal : ";
    Inorder(root);
    cout << "\nPreOrder Traversal : ";
    PreOrder(root);
    cout << endl
         << "Maximum element = " << getMax(root) << endl
         << "Minimum element = " << getMin(root) << endl;
    free(root);
    return 0;
}