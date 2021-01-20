#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Tree;

Tree *CreateBSTfromArray(int *arr, int l, int h)
{
    if (l > h)
        return NULL;
    int mid = l + (h - l) / 2;
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->data = arr[mid];
    root->left = CreateBSTfromArray(arr, l, mid - 1);
    root->right = CreateBSTfromArray(arr, mid + 1, h);
    return root;
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
void preOrder(Tree *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    else
        return;
}
int main()
{
    int size;
    cout << "Enter Array Size : ";
    cin >> size;
    int *arr = (int *)malloc(sizeof(int) * size);
    cout << "Enter Array Elements(in Sorted Order) : ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    Tree *root = CreateBSTfromArray(arr, 0, size);
    cout << "\nBST Created!\nInorder trversal : ";
    Inorder(root);
    cout << "\nPreOrder traversal : ";
    preOrder(root);
    free(arr);
    free(root);
    return 0;
}