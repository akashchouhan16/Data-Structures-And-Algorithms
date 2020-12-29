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
int maxDepth(Tree *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    if (!root->left)
        return maxDepth(root->right) + 1;
    if (!root->right)
        return maxDepth(root->left) + 1;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int main()
{
    Tree *root = createBinarytree();
    cout << "Binary tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    cout << "\nMaximum Height of the Binary tree : " << maxDepth(root) << endl;
    free(root);
    return 0;
}