// To Obtain all the Leaf Nodes to form elements of a linked list.
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
typedef struct node
{
    int data;
    struct node *next;
} linkedlist;

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
void Extractleaves(Tree *root, linkedlist **head)
{
    if (!root)
    {
        cout << "Empty Tree...NULL List created\n";
        *head = NULL;
        return;
    }
    queue<Tree *> q;
    linkedlist *p = *head;
    q.push(root);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        if (!temp->left && !temp->right)
        {
            // Implies its a leaf.
            linkedlist *t = (linkedlist *)malloc(sizeof(linkedlist));
            t->next = NULL;
            t->data = temp->data; //Copying leaf data.
            if (!(*head))
            {
                *head = p = t;
            }
            else
            {
                p->next = t;
                p = t;
            }
        }
    }
}
void DisplayLinkedlist(linkedlist *head)
{
    if (head)
    {
        cout << head->data << "->";
        DisplayLinkedlist(head->next);
    }
    else
    {
        cout << "NULL\n";
    }
}
int main()
{
    Tree *root = CreateBinaryTree();
    cout << "Binary Tree Created!\n";
    cout << "Inorder Traversal : ";
    Inorder(root);
    linkedlist *head = NULL;
    Extractleaves(root, &head);
    cout << endl
         << "Leaf List : ";
    DisplayLinkedlist(head);
    free(root);
    free(head);
    return 0;
}