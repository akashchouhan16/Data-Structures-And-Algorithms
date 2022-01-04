#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define nullptr NULL
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

ll Solve(string str, ll N, ll K = 0)
{
    if (N == 0)
        return 0;

    priority_queue<int> PQ;
    unordered_map<char, int> mp;
    for (auto ch : str)
        mp[ch]++;

    for (auto x : mp)
    {
        PQ.push(x.second);
    }

    ll sum = 0;
    while (K--)
    {
        int temp = PQ.top();
        PQ.pop();
        temp -= 1;
        PQ.push(temp);
    }
    while (not PQ.empty())
    {
        sum += (PQ.top() * PQ.top());
        PQ.pop();
    }
    return sum;
}
signed main()
{
    v(ll) out;
    tests
    {
        string str;
        cin >> str;
        ll K = 0, N = str.size();
        cin >> K;

        out.pb(Solve(str, N));
    }

    loop(i, out.size()) cout << "Case #" << i + 1 << ": " << out[i] << endl;
    return 0;
}