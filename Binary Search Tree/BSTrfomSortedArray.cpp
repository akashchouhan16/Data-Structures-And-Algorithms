#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;
typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
} Tree;
Tree *root = NULL;
class Solution
{
    vector<int> arr;
    int size;

public:
    Solution()
    {
        cout << "Enter Size : ";
        cin >> size;
        srand(time(NULL));
        for (int i = 0; i < size; i++)
            arr.push_back(1 + rand() % (size + 19));
        sort(arr.begin(), arr.end());
    }
    int getSize() { return arr.size(); }
    void DisplayVector()
    {
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }
    Tree *CreateTree(int l, int h)
    {
        if (l >= h)
            return NULL;

        int mid = l + (h - l) / 2;
        Tree *temp = new Tree();
        temp->data = arr[mid];
        temp->left = CreateTree(l, mid - 1);
        temp->right = CreateTree(mid + 1, h);
        return temp;
    }
    void Inorder(Tree *p)
    {
        if (p)
        {
            Inorder(p->left);
            cout << p->data << ", ";
            Inorder(p->right);
        }
        else
            return;
    }
    void Preorder(Tree *root)
    {
        if (root)
        {
            cout << root->data << ", ";
            Preorder(root->left);
            Preorder(root->right);
        }
        else
            return;
    }
};

int main()
{
    Tree *root = NULL;
    Solution obj;
    cout << "Input vector : ";
    obj.DisplayVector();
    cout << endl
         << "Creating BST...\n";
    root = obj.CreateTree(0, obj.getSize());
    cout << "Inorder Traversal : ";
    obj.Inorder(root);
    cout << endl
         << "Preorder Traversal  : ";
    obj.Preorder(root);
    free(root);
    return 0;
}