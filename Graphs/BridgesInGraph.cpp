/*Problem Statement : For a Graph DS, a bridge is an edge removing which increases number of disconnected components. Find all the V1<->V2 bridges for an input Graph.
INPUT Format :
    1. test Cases
    2. Vertices and Edges of Graph
    3. All U and V inputs for the Graph.

Sample Test Cases : 
2
5 5
0 1
0 2
0 3
1 2
3 4
4 3
0 1
1 2
2 3
Bridges In The Input Graph :
case #1
a) 2->3
b) 1->2
c) 0->1
case #2
a) 2->3
b) 1->2
c) 0->1

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

// OUTPUT ;
v(p(int, int)) OUTPUT;
inline int min(int &X, int &Y) { return X < Y ? X : Y; }

void DFS(int src, int parent, v(bool) & visited, v(int) & Tin, v(int) & Low, int &timer, v(int) adj[])
{
    visited[src] = true;
    Tin[src] = Low[src] = ++timer;

    // for (auto x : adj[src])
    for (int x = 0; x < adj[src].size(); x++)
    {
        if (adj[src][x] == parent)
            continue;

        if (not visited[adj[src][x]])
        {
            DFS(adj[src][x], src, visited, Tin, Low, timer, adj);
            Low[src] = min(Low[src], Low[adj[src][x]]);
            if (Low[adj[src][x]] > Tin[src])
            {
                OUTPUT.pb(make_pair(src, adj[src][x]));
            }
        }
        else
        {
            Low[src] = min(Low[src], Tin[adj[src][x]]);
        }
    }
    return;
}

void Solve(int &V, v(int) adj[])
{
    v(int) Tin(V, -1);
    v(int) Low(V, -1);
    v(bool) visited(V, false); //for DFS

    int timer = 0;

    for (int i = 0; i < V; i++)
    {
        if (not visited[i])
            DFS(i, -1, visited, Tin, Low, timer, adj);
    }
    return;
}
signed main()
{
    v(v(p(int, int))) SOLUTION;
    tests
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        OUTPUT.erase(all(OUTPUT));
        Solve(V, adj);

        SOLUTION.pb(OUTPUT);
    }
    cout << "Bridges In The Input Graph : \n";
    loop(i, SOLUTION.size())
    {
        cout << "case #" << i + 1 << "\n";
        loop(j, OUTPUT.size()) cout << (char)(97 + j) << ") " << OUTPUT[j].first << "->" << OUTPUT[j].second << endl;
    }
    return 0;
}