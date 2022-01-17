/*Problem Statement:
Sample Test Cases:
PreOrder Traversal: 1,2,4,7,3,5,6,
Enter the Starting Node: 2
3 units.
*/
#include <bits/stdc++.h>
#include <algorithm>

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

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int _val = 0) : val(_val), left(nullptr), right(nullptr) {}
};

TreeNode *createBinaryTree()
{
    int value = -1;
    std::cin >> value;
    if (value <= -1)
        return nullptr;
    TreeNode *root = new TreeNode(value);
    std::cout << "Enter the Left Child of " << root->val << ": ";
    root->left = createBinaryTree();
    std::cout << "Enter the Right Child of " << root->val << ": ";
    root->right = createBinaryTree();

    return root;
}

class Solution
{
    TreeNode *root;
    int start; // Start Node.
    int timeToBurn;
    TreeNode *startNode;

public:
    Solution() : timeToBurn(0) { this->root = createBinaryTree(); }
    inline void setStartNode(int startNode = 0)
    {
        this->start = startNode;
        this->startNode = this->root ? this->root->left : this->root; // temporary.
    }
    inline TreeNode *getRoot() { return this->root; }
    void preOrder(TreeNode *);
    void inOrder(TreeNode *);

    void computeTimeToBurn();
    inline int getTimeToBurn() { return this->timeToBurn; }
};
void Solution::preOrder(TreeNode *root)
{
    if (root)
    {
        std::cout << root->val << ",";
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}
void Solution::inOrder(TreeNode *root)
{
    if (root)
    {
        inOrder(root->left);
        std::cout << root->val << ",";
        inOrder(root->right);
    }
    return;
}
/*
WE need to radially move outwards from the starting node, and increament the time by 1unit for every level in our BFS.
we would also need a visited[] or map to keep track of all the visited nodes in our Tree.
Once all the Tree nodes are burned, we terminate the BFS and update the this->timeToBurn to the counter value;
*/
void getParents(TreeNode *root, map<TreeNode *, TreeNode *> parent)
{
    queue<TreeNode *> Q;
    Q.push(root);

    while (not Q.empty())
    {
        TreeNode *current = Q.front();
        Q.pop();

        if (current->left)
        {
            parent[current->left] = current;
            Q.push(current->left);
        }
        if (current->right)
        {
            parent[current->right] = current;
            Q.push(current->right);
        }
    }
    return;
}
void Solution::computeTimeToBurn()
{
    map<TreeNode *, TreeNode *> parent;
    getParents(root, parent); // compute and store all the Node<->Parent mapping for radial traversal.

    map<TreeNode *, bool> visited;
    visited[startNode] = true;

    queue<TreeNode *> Q;
    Q.push(startNode);
    int timer = 0;

    while (not Q.empty())
    {
        int N = Q.size();
        timer++;
        for (int i = 0; i < N; i++)
        {
            TreeNode *current = Q.front();
            Q.pop();

            if (current->left and !visited[current->left])
            {
                visited[current->left] = true;
                Q.push(current->left);
            }
            if (current->right and !visited[current->right])
            {
                visited[current->right] = true;
                Q.push(current->right);
            }
            if (parent[current] and !visited[parent[current]])
            {
                visited[parent[current]] = true;
                Q.push(parent[current]);
            }
        }
    }
    this->timeToBurn = timer;
    return;
}

int main()
{
    Solution obj;
    TreeNode *root = obj.getRoot();
    int startNode;

    std::cout << "\nPreOrder Traversal: ";
    obj.preOrder(root);
    std::cout << "\nEnter the Starting Node: ";
    std::cin >> startNode;
    obj.setStartNode(startNode);

    obj.computeTimeToBurn();
    std::cout << obj.getTimeToBurn() << " units.\n";

    return 0;
}