#include <iostream>
#include <cstdlib>
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
    cout << "For Left Child of " << temp->data;
    temp->left = CreateBinaryTree();
    cout << "For Right Child of " << temp->data;
    temp->right = CreateBinaryTree();
    return temp;
}
void DisplayInorder(Tree *root)
{
    if (root)
    {
        DisplayInorder(root->left);
        cout << root->data << " ";
        DisplayInorder(root->right);
    }
    else
        return;
}
int sizeofBinaryTree(Tree *root)
{
    if (!root)
        return 0;
    else
        return (sizeofBinaryTree(root->left) + sizeofBinaryTree(root->right) + 1);
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder Traversal : ";
    DisplayInorder(root);
    cout << "\nSize of the Binary Tree : " << sizeofBinaryTree(root) << endl;
    free(root);
    return 0;
}