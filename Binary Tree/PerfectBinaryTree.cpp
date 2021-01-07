#include <iostream>
#include <cstdlib>
#include <stack>
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
    cout << "Enter data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    temp->data = data;
    cout << "For Left Child of " << temp->data << " ";
    temp->left = CreateBinaryTree();
    cout << "For Right Child of " << temp->data << " ";
    temp->right = CreateBinaryTree();

    return temp;
}

void DisplayInorder(Tree *root)
{
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
bool Utility(Tree *root, int depth, int level = 0)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
    {
        return (depth == level + 1);
    }
    if (!root->left || !root->right)
        return false;
    return Utility(root->left, depth, level + 1) && Utility(root->right, depth, level + 1);
}
int findDepth(Tree *root)
{
    int x, y;
    if (root)
    {
        x = findDepth(root->left);
        y = findDepth(root->right);
        return (x > y) ? x + 1 : y + 1;
    }
    else
        return 0;
}
bool isPerfectBinarytree(Tree *root)
{
    int depth = findDepth(root);
    return Utility(root, depth);
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder Traversal : ";
    DisplayInorder(root);
    if (isPerfectBinarytree(root))
    {
        cout << "\nYes, Input Binary tree is a Perfect Binary tree.\n";
    }
    else
        cout << "\nThe Input Binary tree is not a perfect Binary tree.\n";

    free(root);
    return 0;
}
