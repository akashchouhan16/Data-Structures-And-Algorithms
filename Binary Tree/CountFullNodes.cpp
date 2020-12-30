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
// Recurssive
int CountFullNodes(Tree *root)
{
    static int count = 0;
    if (root)
    {
        CountFullNodes(root->left);
        CountFullNodes(root->right);
        if (root->left && root->right)
            count++;
    }
    return count;
}
// Iterative
int CountFullNodesRec(Tree *root)
{
    if (!root)
        return 0;
    int count = 0;
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        if (temp->left && temp->right)
            count++;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return count;
}
int main()
{
    Tree *root = createBinarytree();
    cout << "Binary tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    cout << "\nNumber of Half Nodes  = " << CountFullNodes(root) << endl
         << "Number of Half Nodes(Recurr) = " << CountFullNodesRec(root) << endl;
    free(root);
    return 0;
}