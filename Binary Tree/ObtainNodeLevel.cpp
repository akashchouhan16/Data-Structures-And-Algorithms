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
int NodeLevelUtility(Tree *root, int data, int level)
{
    if (!root)
        return 0;
    if (root->data == data)
        return level;
    int newLevel = NodeLevelUtility(root->left, data, level + 1);
    if (newLevel != 0)
        return newLevel;
    newLevel = NodeLevelUtility(root->right, data, level + 1);
    if (newLevel != 0)
        return newLevel;
}
int getNodeLevel(Tree *root, int data)
{
    return NodeLevelUtility(root, data, 1);
}
int main()
{
    Tree *root = createBinarytree();
    cout << "Binary tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    int key;
    cout << "\nEnter Node data : ";
    cin >> key;
    cout << "Level of Node with Data " << key << " is : " << getNodeLevel(root, key) << endl;
    free(root);
    return 0;
}