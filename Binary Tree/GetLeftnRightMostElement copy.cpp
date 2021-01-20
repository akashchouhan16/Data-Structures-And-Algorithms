// To obtain the LeftMost and RightMost Element in a Binary Tree.
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
Tree *LeftMostNode(Tree *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}
Tree *RightMostElement(Tree *root)
{
    while (root && root->right)
    {
        root = root->right;
    }
    return root;
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary tree Created!\n";
    cout << "Inorder Traversal : ";
    DisplayInorder(root);
    cout << "\nLeft Most Element : " << LeftMostNode(root)->data << endl;
    cout << "Right Most Element : " << RightMostElement(root)->data << endl;
    free(root);
    return 0;
}