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
int height(Tree *root)
{
    if (!root)
        return 0;
    queue<Tree *> q;
    q.push(root);
    int ht = 0;
    while (1)
    {
        int count = q.size();
        if (count == 0)
            return ht;
        ht++;
        while (count > 0)
        {
            Tree *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            count--;
        }
    }
}

int main()
{
    Tree *root = NULL;
    int ch;
    printf("Enter 1 to Create a Binary tree\nEnter 2 to Inorder Traverse\nEnter 3 to find Tree Height\nEnter 4 to Exit().\n");
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
            cout << "Height of the Binary tree = " << height(root) << "\n";
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