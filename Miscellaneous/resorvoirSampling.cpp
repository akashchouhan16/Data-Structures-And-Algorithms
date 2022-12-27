/*Problem Statement: Implement Resorvoir Sample to generate k random values with equal probability. Reservoir sampling is a family of randomized algorithms for randomly choosing k samples from a list of n items, where n is either a very large or unknown number. Typically n is large enough that the list doesn’t fit into main memory. For example, a list of search queries in Google and Facebook. So we are given a big array (or stream) of numbers (to simplify), and we need to write an efficient function to randomly select k numbers where 1 <= k <= n. Let the input array be stream[].

Sample Test Cases:
2
12 5
1 2 3 4 5 6 7 8 9 10 11 12
Sampling Values: 11, 12, 6, 4, 5,
7 7
3 5 7 4 6 9 11
Sampling Values: 3, 5, 7, 4, 6, 9, 11,
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

void Solve(v(ll) & stream, ll &n, ll &k)
{
    v(ll) values(k);
    for (ll i = 0; i < k; i++)
        values[i] = stream[i];
    srand(time(nullptr));

    ll i = k;
    for (; i < n; i++)
    {
        ll j = rand() % (i + 1);
        if (j < k)
            values[j] = stream[i];
    }

    cout << "Sampling Values: ";
    for (ll i = 0; i < k; i++)
        cout << values[i] << ", ";
    cout << endl;
    return;
}
signed main()
{
    tests
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> stream(n);

        loop(i, n) cin >> stream[i];
        Solve(stream, n, k);
    }
    return 0;
}