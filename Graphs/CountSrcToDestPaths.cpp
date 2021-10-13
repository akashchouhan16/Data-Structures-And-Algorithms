/*Problem Statement : 

Sample Test Case :
3
4 5
1 2
1 3
1 4
2 3
2 4
Enter Source Node and Dest Node : 1 4
5 6
0 1
0 3
3 1
1 2
1 4
2 4
Enter Source Node and Dest Node : 0 4
6 9
0 1
0 2
1 2
1 3
2 3
2 4
3 4
3 5
4 5
Enter Source Node and Dest Node : 0 5
case #1 : 8
case #2 : 20
case #3 : 48
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

void DFSUtil(int src, int dest, v(int) adj[], v(bool) & visited, int &count)
{
    if (src == dest)
    {
        count += 1;
        return;
    }
    visited[src] = true;
    for (auto x : adj[src])
    {
        if (not visited[x])
            DFSUtil(x, dest, adj, visited, count);
    }
    visited[src] = false;
    return;
}
int Solve(v(int) adj[], int &V, int &src, int &dest)
{
    if (not V)
        return 0;
    int count = 0;
    v(bool) visited(V, false);
    loop(i, V)
    {
        if (not visited[i])
            DFSUtil(src, dest, adj, visited, count);
    }

    return count;
}

signed main()
{
    v(int) OUTPUT;
    tests
    {
        int V, E, src, dest;
        cin >> V >> E;
        v(int) adj[V]; //adjacency list for a Directed Graph.
        loop(j, E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        cout << "Enter Source Node and Dest Node : ";
        cin >> src >> dest;
        OUTPUT.pb(Solve(adj, V, src, dest));
    }

    loop(i, OUTPUT.size()) cout << "case #" << i + 1 << " : " << OUTPUT[i] << endl;
    return 0;
}