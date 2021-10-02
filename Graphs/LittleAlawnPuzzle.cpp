/*
Problem Statement : When he's not training for IOI, Little Alawn enjoys playing with puzzles of various types to stimulate his brain. Today, he's playing with a puzzle that consists of a 2×n grid where each row is a permutation of the numbers 1,2,3,…,n.
The goal of Little Alawn's puzzle is to make sure no numbers on the same column or row are the same (we'll call this state of the puzzle as solved), and to achieve this he is able to swap the numbers in any column. However, after solving the puzzle many times, Little Alawn got bored and began wondering about the number of possible solved configurations of the puzzle he could achieve from an initial solved configuration only by swapping numbers in a column.
Unfortunately, Little Alawn got stuck while trying to solve this harder problem, so he was wondering if you could help him with it. Find the answer modulo 109+7.
SAMPLE TEST CASE-
2
4
1 4 2 3
3 2 1 4
8
2 6 5 1 4 3 7 8
3 8 7 5 1 2 4 6

OUTPUT-
2
8
*/

int FastModExp(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
vector<int> adj[1000000];
int vis[1000001];
void bfs(int src)
{
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto u : adj[x])
        {
            if (vis[u] == 0)
            {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
}
void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = 0;
    }
    vi v1(n), v2(n);
    for (int i = 0; i < n; i++)cin >> v1[i];
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
        adj[v1[i]].pb(v2[i]);
    }
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            bfs(i);
            ct++;
        }
    }
    cout << FastModExp(2, ct) << "\n";
    return;
}
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)solve();
}
