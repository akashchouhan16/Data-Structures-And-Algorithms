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
void getMaxLevelSum(Tree *root, int &res)
{
    if (!root)
    {
        res = -1;
    }
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        int currentsum = 0;
        while (count--)
        {
            Tree *temp = q.front();
            q.pop();
            currentsum += temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (currentsum > res)
            res = currentsum;
    }
    return;
}

int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    int sum;
    getMaxLevelSum(root, sum);
    cout << "Maximum Level Sum : " << sum << endl;
    free(root);
    return 0;
}