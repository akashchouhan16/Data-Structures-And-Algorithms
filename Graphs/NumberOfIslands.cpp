/*Problem Statement : An island(1) is surrounded by water(0) and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.

Sample Test Case : 
3
5 4
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
5 4
1 1 0 0 0
1 1 0 1 0
0 0 1 0 0
0 0 0 1 1
5 5
0 0 0 1 1
1 0 0 1 0
1 1 0 0 1
0 0 0 0 0
0 1 1 0 1
case #1 : 2
case #2 : 3
case #3 : 5
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define ll long long
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define pp() pop_back()
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

#define tests \
    int t;    \
    cin >> t; \
    while (t--)

void DFS(v(v(int)) & adj, int i, int j, int rows, int cols)
{
    if (i < 0 or j < 0 or i >= rows or j >= cols or adj[i][j] != 1)
        return;
    // mark the island as visited
    adj[i][j] = 0;

    DFS(adj, i + 1, j, rows, cols);
    DFS(adj, i, j + 1, rows, cols);
    DFS(adj, i - 1, j, rows, cols);
    DFS(adj, i, j - 1, rows, cols);
    return;
}

int GetNumberOfIslands(v(v(int)) adj, int &V)
{
    if (!V)
        return 0;
    int rows = V, cols = adj[0].size(), islandCount = 0;

    loop(i, rows)
    {
        loop(j, cols)
        {
            if (adj[i][j] == 1)
            {
                DFS(adj, i, j, rows, cols);
                islandCount += 1;
            }
        }
    }
    return islandCount;
}
signed main()
{
    v(int) OUTPUT;
    tests
    {
        int V, E;
        cin >> V >> E;
        v(v(int)) adj(V, vector<int>(E)); //adjacency mat.
        loop(i, V)
        {
            loop(j, E)
            {
                int x;
                cin >> x;
                adj[i][j] = x;
            }
        }

        OUTPUT.pb(GetNumberOfIslands(adj, V));
    }

    loop(i, OUTPUT.size()) cout << "case #" << i + 1 << " : " << OUTPUT[i] << endl;
    return 0;
}