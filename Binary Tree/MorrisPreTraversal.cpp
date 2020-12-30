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

void MorrisPreOrdertraversal(Tree *root)
{
    while (root)
    {
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            Tree *current = root->left;
            while (current->right && current->right != root)
                current = current->right;

            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }
            else
            {
                cout << root->data << " ";
                current->right = root;
                root = root->left;
            }
        }
    }
    return;
}

int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Morris PreOrder : ";
    MorrisPreOrdertraversal(root);
    free(root);
    return 0;
}