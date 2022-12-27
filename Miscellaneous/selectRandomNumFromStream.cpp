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

void Solve(v(ll) & stream, ll &n, ll k)
{
    ll value;
    value = stream[0];

    srand(time(nullptr));
    for (ll i = 1; i < n; i++)
    {
        ll j = rand() % (i + 1);
        if (j < k)
            value = stream[j];
    }

    cout << "Value: " << value << endl;
    return;
}
signed main()
{
    tests
    {
        ll n;
        cin >> n;
        vector<ll> stream(n);

        loop(i, n) cin >> stream[i];
        Solve(stream, n, 1); // k = 1.
    }
    return 0;
}