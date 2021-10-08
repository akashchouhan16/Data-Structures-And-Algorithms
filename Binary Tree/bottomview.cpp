/* Problem Statement : Given a binary tree , print its bottom view

Sample Test Case - 
I/P : 1 2 3 4 NULL 6 7 NULL NULL NULL 8 NULL NULL
O/P : 4 2 6 8 7
*/

#include<bits/stdc++.h>
using namespace std;
// A tree node
struct Tree
{
	int data;
	Tree *left;
	Tree *right;
  Tree(int data) 
    { 
        this -> data = data; 
        left = NULL;
        right = NULL; 
    }     
};
void bottomview(Tree * root, map<int,vector<int>>& m, int lev, int h_dist)
{
  // Base case
  if (root == NULL)
    return;
  
  if (m.find(h_dist) == m.end())
  {   
    m[h_dist].push_back(lev);
    m[h_dist].push_back(root -> data);
  }
  
  else
  {
    if (m[h_dist][0] <= lev) 
    {
      m[h_dist][0] = lev;
      m[h_dist][1]= root -> data;
    }
  }
  
  bottomview(root -> left, m, lev + 1, h_dist - 1);
  bottomview(root -> right, m, lev + 1, h_dist + 1);
}
int main() 
{
  // Creating a tree
  Tree *root = new Tree(1); 
  root -> left = new Tree(2); 
  root -> right = new Tree(3); 
  root -> left -> left = new Tree(4); 
  root -> right -> left = new Tree(6);
  root -> right -> right = new Tree(7);
  root -> right -> left -> right = new Tree(8);
  map<int,vector<int>> Map;
  bottomview(root, Map, 1, 0);
  for (auto it = Map.begin(); it != Map.end(); ++it)
  {
    cout << (it-> second)[1]<< " ";
  }
  cout<<endl;
  return 0;
}
