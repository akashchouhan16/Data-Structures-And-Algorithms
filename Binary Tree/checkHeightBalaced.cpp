#include <cstdlib>
#include <iostream>
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
    int ch, data;
    temp = (Tree *)malloc(sizeof(Tree));
    temp->left = temp->right = NULL;
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
void InOrder(Tree *root)
{
    if (root)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
    else
        return;
}
int Height(Tree *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = Height(root->left);
        y = Height(root->right);
        return (x > y) ? x + 1 : y + 1;
    }
    return 0;
}
int isBalanced(Tree *root)
{
    if (!root)
        return 1;
    int lh = Height(root->left);
    int rh = Height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
int main()
{
    Tree *root = NULL;
    int ch;
    printf("Enter 1 to Create a Binary tree\nEnter 2 to Inorder Traverse\nEnter 3 to check if its Height Balaced\nEnter 4 to Exit().\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            root = CreateBinaryTree();
            cout << "Binary Tree Created!\n";
        }
        else if (ch == 2)
        {
            cout << "Inorder traversal : ";
            InOrder(root);
        }
        else if (ch == 3)
        {
            if (isBalanced(root))
                cout << "The Binary Tree is Height Balanced!\n";
            else
                cout << "The Binary Tree is not Height Balaced!\n";
        }
        else
        {
            if (ch != 0)
                cout << "Invalid Choice!\n";
            else
            {
                cout << "Code Terminated!\n";
                break;
            }
        }
    } while (ch != 0);
    free(root);
    return 0;
}