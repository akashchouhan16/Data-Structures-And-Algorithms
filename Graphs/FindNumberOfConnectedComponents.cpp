/*Problem Statement : 

Sample Test Case :
2
6 3
0 2
1 5
2 4
10 8
0 1
1 2
1 3
2 3
4 5
4 7
6 8
6 9
case #1 : 3
case #2 : 3

Approach I :
Number of connected components -> If there is only a single component, then One DFS call can cover all the vertices, however if N DFS calls are requried before every vectex if visited, then the number of components in our graph is N.
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

void DFS(v(int) adj[], int src, v(bool) & visited)
{
    visited[src] = true;
    for (int i = 0; i < adj[src].size(); i++)
    {
        if (not visited[adj[src][i]])
            DFS(adj, adj[src][i], visited);
    }
    return;
}

int Solve(v(int) adj[], int &V)
{
    if (!V)
        return 0;

    int count = 0;
    v(bool) visited(V, false);

    loop(i, V)
    {
        if (not visited[i])
        {
            DFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

signed main()
{
    v(int) OUTPUT;
    tests
    {
        int V, E;
        cin >> V >> E;
        v(int) adj[V]; //adjacency list.
        loop(j, E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        OUTPUT.pb(Solve(adj, V));
    }

    loop(i, OUTPUT.size()) cout << "case #" << i + 1 << " : " << OUTPUT[i] << endl;
    return 0;
}