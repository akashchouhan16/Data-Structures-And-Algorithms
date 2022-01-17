#include <bits/stdc++.h>
#define nullptr NULL
#define INF INT_MAX
using namespace std;

// A tree node
struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int _data = 0) : data(_data), left(nullptr), right(nullptr) {}
};

class BoundaryOrderTraversal
{
protected:
    TreeNode *root;
    vector<int> output;

public:
    BoundaryOrderTraversal(TreeNode *_root = nullptr) : root(_root)
    {
        output.clear();
    }
    inline TreeNode *getRoot() { return this->root; }
    TreeNode *createTree();
    void boundaryOrder(TreeNode *);
    void display()
    {
        for (auto &x : output)
            std::cout << x << " " << std::endl;
    }
};
inline bool isLeaf(TreeNode *root)
{
    return (root and !root->left and !root->right);
}

void preOrder(TreeNode *root)
{
    if (root)
    {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    else
        return;
}
void addLeafBoundary(TreeNode *root, vector<int> &output)
{
    while (root)
    {
        if (!isLeaf(root))
            output.push_back(root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}
void addRightBoundary(TreeNode *root, vector<int> &output)
{
    stack<int> St;
    while (root)
    {
        if (not isLeaf(root))
            St.push(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }

    while (not St.empty())
    {
        output.push_back(St.top());
        St.pop();
    }
    return;
}
void addLeaf(TreeNode *root, vector<int> &output)
{
    if (isLeaf(root))
    {
        output.push_back(root->data);
        return;
    }
    addLeaf(root->left, output);
    addLeaf(root->right, output);
}
void BoundaryOrderTraversal::boundaryOrder(TreeNode *root)
{
    if (not root)
        return;
    if (not isLeaf(root))
        this->output.push_back(root->data);
    addLeafBoundary(root->left, output);
    addLeaf(root, output);
    addRightBoundary(root->right, output);
    return;
}

TreeNode *BoundaryOrderTraversal::createTree()
{
    int _value = -1;
    std::cin >> _value;
    if (_value <= -1)
        return nullptr;
    TreeNode *root = new TreeNode(_value);
    std::cout << "Enter the Left Child of " << root->data << ": ";
    root->left = createTree();
    std::cout << "Enter the Right Child of " << root->data << ": ";
    root->right = createTree();

    return (this->root = root);
}

signed main()
{
    BoundaryOrderTraversal obj;
    obj.createTree();
    TreeNode *root = obj.getRoot();
    // preOrder(root);
    obj.boundaryOrder(root);
    obj.display();
    delete root;
    return 0;
}