/*
Problem Statement: Write a class to serialise and deserialise a binary tree.
Serialise: [Tree]->[encoded_string]
Deserialise: [encoded_string]->[Tree]

Sample Tests:
Serialised Binary Tree: 1,2,3,#,6,4,5,#,#,#,#,#,#,
Binary Tree After Deserialisation: 1, 2, 6, 3, 4, 5,
*/
#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>

#define MOD 1e9 + 7
#define nullptr NULL
#define INF INT_MAX
#define ff first
#define ss second
#define ll long long
#define lb long double
#define g(x) greater<x>
#define loop(i, n) for (int i = 0; i < n; i++)
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define mp make_pair
#define pb(x) push_back(x)
#define pp() pop_back()
#define all(x) x.begin(), x.end()
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;
// Node structure for the Binary Tree Class.
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    TreeNode *root;

public:
    BinaryTree(TreeNode *_root = nullptr) : root(_root) {}
    inline TreeNode *getRoot() { return this->root; }
    TreeNode *createBinaryTree();
    void preOrder(TreeNode *);
};
TreeNode *BinaryTree::createBinaryTree()
{
    int _value = -1;
    std::cin >> _value;
    if (_value <= -1)
        return nullptr;
    TreeNode *root = new TreeNode(_value);
    std::cout << "Enter the left Child of " << root->val << ": ";
    root->left = createBinaryTree();
    std::cout << "Enter the right Child of " << root->val << ": ";
    root->right = createBinaryTree();

    this->root = root;
    return root;
}
void BinaryTree::preOrder(TreeNode *root)
{
    if (root)
    {
        std::cout << root->val << ", ";
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}

// Serialise & Deserialise a Binary Tree.
class Serialise_Deserialise
{
    TreeNode *root;
    string encodedString;

public:
    Serialise_Deserialise(TreeNode *_root = nullptr) : root(_root), encodedString("") {}
    string Serialise(TreeNode *);
    TreeNode *Deserialise(string);
};
string Serialise_Deserialise::Serialise(TreeNode *root)
{
    if (not root)
        return (encodedString = "");

    queue<TreeNode *> Q;
    Q.push(root);

    while (not Q.empty())
    {
        TreeNode *node = Q.front();
        Q.pop();

        if (node == nullptr)
            encodedString += "#,";
        if (node)
        {
            encodedString += (to_string(node->val) + ",");
            Q.push(node->left);
            Q.push(node->right);
        }
    }
    return encodedString;
}
TreeNode *Serialise_Deserialise::Deserialise(string str)
{
    if (str == "")
        return (this->root = nullptr);

    queue<TreeNode *> Q;
    stringstream s(str);
    string data;
    getline(s, data, ',');
    TreeNode *root = new TreeNode(stoi(data));
    Q.push(root);

    while (not Q.empty())
    {
        TreeNode *node = Q.front();
        Q.pop();

        getline(s, data, ',');
        if (data == "#")
            node->left = nullptr;
        else
        {
            node->left = new TreeNode(stoi(data));
            Q.push(node->left);
        }

        getline(s, data, ',');
        if (data == "#")
            node->right = nullptr;
        else
        {
            node->right = new TreeNode(stoi(data));
            Q.push(node->right);
        }
    }
    return this->root = root;
}
signed main()
{
    BinaryTree *obj = new BinaryTree();
    obj->createBinaryTree();
    TreeNode *root = obj->getRoot();

    // obj->preOrder(root);

    Serialise_Deserialise object(root);
    string encoded_string = object.Serialise(root);

    std::cout << "Serialised Binary Tree: " << encoded_string << std::endl;

    TreeNode *newRoot = object.Deserialise(encoded_string);
    std::cout << "Binary Tree After Deserialisation: ";
    obj->preOrder(newRoot);

    return 0;
}