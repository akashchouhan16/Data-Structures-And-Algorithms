#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

typedef struct Node
{
    string data;
    struct Node *left;
    struct Node *right;
} ExpressionTree;

ExpressionTree *CreateExpTree()
{
    ExpressionTree *temp = new ExpressionTree();
    string data;
    cout << "Enter character : ";
    cin >> data;
    if (data == "\0" || data == "$")
        return NULL;
    temp->data = data;
    cout << "For Left Child of " << temp->data << ",";
    temp->left = CreateExpTree();
    cout << "For Right Child of " << temp->data << ",";
    temp->right = CreateExpTree();
    return temp;
}
void Inorder(ExpressionTree *root)
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
int toInt(string s)
{
    int num = 0;
    if (s[0] != '-')
        for (int i = 0; i < s.length(); i++)
            num = num * 10 + (int(s[i]) - 48);
    else
        for (int i = 1; i < s.length(); i++)
        {
            num = num * 10 + (int(s[i]) - 48);
            num = num * -1;
        }

    return num;
}
int evaluate(ExpressionTree *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
        return toInt(root->data);
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);
    if (root->data == "+")
        return leftValue + rightValue;
    if (root->data == "-")
        return leftValue - rightValue;
    if (root->data == "*")
        return leftValue * rightValue;
    return leftValue / rightValue;
}
int main()
{
    ExpressionTree *root = CreateExpTree();
    cout << "Expression Tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    cout << "Evaluated Value = " << evaluate(root) << endl;
    free(root);
    return 0;
}