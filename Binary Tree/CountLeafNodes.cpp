#include <iostream>
#include <cstdlib>
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
    Tree *temp = NULL;
    int data;
    temp = (Tree *)malloc(sizeof(Tree));
    cout << "Enter Data : ";
    cin >> data;
    if (data == -1)
        return NULL;
    temp->data = data;
    cout << "Enter Left Child of " << temp->data << " : ";
    temp->left = CreateBinaryTree();
    cout << "Enter Right Child of " << temp->data << " : ";
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
// Recurssive.
int CountLeaf(Tree *root)
{
    static int count = 0;
    if (root)
    {
        CountLeaf(root->left);
        CountLeaf(root->right);
        if (!root->left && !root->right)
            count++;
    }
    return count;
}
// Iterative
int CountleafRec(Tree *root)
{
    queue<Tree *> q;
    if (!root)
        return 0;
    int count = 0;
    q.push(root);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        if (temp->left == NULL && temp->right == NULL)
            count++;
    }
    return count;
}
int main()
{
    Tree *root = NULL;

    root = CreateBinaryTree();
    cout << "Binary tree Created!\n";
    cout << "Inorder traversal : ";
    Inorder(root);
    cout << endl
         << "PreOrder traversal : ";
    PreOrder(root);
    cout << endl
         << "Number of Leaf Nodes = " << CountLeaf(root) << endl
         << "Recurssive Count leaf Nodes = " << CountleafRec(root) << endl;

    free(root);
    return 0;
}
