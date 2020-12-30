#include <cstdlib>
#include <iostream>
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
// leftView - Iterative Traversal.
void leftView(Tree *root)
{

    if (!root)
        return;
    queue<Tree *> q;
    q.push(root);

    while (!q.empty())
    {

        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Tree *temp = q.front();
            q.pop();
            if (i == 1)
                cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
                q.push(temp->right);
        }
    }
    return;
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

int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!";
    cout << "\nInorder : ";
    DisplayInorder(root);
    cout << "\nLeft View of the Binary Tree : ";
    leftView(root);
    delete root;
    return 0;
}