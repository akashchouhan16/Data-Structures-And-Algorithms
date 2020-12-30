#include <cstdlib>
#include <iostream>
#include <stack>
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
    cout << "Enter the Data : ";
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
void Inorder(Tree *root)
{
    if (!root)
        return;
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
void getSecondLargest(Tree *root, int &result)
{
    if (!root)
    {
        result = -99;
        return;
    }
    int max = -1;
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        if (temp->data > max)
        {
            result = max;
            max = temp->data;
        }
        if (temp->data < max && temp->data > result)
        {
            result = temp->data;
        }
    }
    return;
}

int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    int element;
    getSecondLargest(root, element);
    cout << "\nSecond Largest Element : " << element << endl;

    free(root);
    return 0;
}