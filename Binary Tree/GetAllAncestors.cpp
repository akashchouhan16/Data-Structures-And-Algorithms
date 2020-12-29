#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Tree;

Tree *createBinarytree()
{
    Tree *temp = new Tree();
    int data;
    cout << "Enter Data : ";
    cin >> data;
    if (data == -1)
        return NULL;
    temp->data = data;
    cout << "For Left Child of " << temp->data << " ";
    temp->left = createBinarytree();
    cout << "For Right Child of " << temp->data << " ";
    temp->right = createBinarytree();
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
bool GetAncestors(Tree *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    if (GetAncestors(root->left, key) || GetAncestors(root->right, key))
    {
        cout << root->data << " ";
        return true;
    }
    return false;
}
int main()
{
    Tree *root = createBinarytree();
    cout << "Binary tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    int key;
    cout << "\nEnter Target Node : ";
    cin >> key;
    cout << "Are the Ancestors of the Key Node." << GetAncestors(root, key) << endl;
    free(root);
    return 0;
}