/*Problem Statement: A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
[Below is the Optimsed Approach to this Problem -> O(N^2) Time]

Sample Test Case:
3
3
0 1 0
0 0 0
0 1 0
5
0 1 1 0 0
1 0 1 0 1
0 0 0 0 0
0 1 1 1 1
1 0 1 1 0
2
0 1
1 0
Case #1: 1
Case #2: 2
Case #3: -1
*/
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

ll Solve(v(v(int)) arr, ll N)
{
    if (N == 0)
        return -1;
    ll candidate = 0;
    for (ll i = 1; i < N; i++)
    {
        if (arr[candidate][i])
            candidate = i;
    }
    // Confirm Candidate:
    loop(i, N)
    {
        if (i != candidate and (arr[candidate][i] == 1 or arr[i][candidate] == 0))
            return -1;
    }
    return candidate;
}
signed main()
{
    v(ll) out;
    tests
    {
        ll N;
        cin >> N;
        v(v(int)) arr(N, v(int)(N));
        loop(i, N)
        {
            loop(j, N) cin >> arr[i][j];
        }
        out.pb(Solve(arr, N));
    }

    loop(i, out.size()) cout << "Case #" << i + 1 << ": " << out[i] << endl;
    return 0;
}