#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define MOD ll(1e9 + 7)
#define vi vector<int>
#define v(x) vector<x>
#define p(x) pair<x, x>
#define pb(x) push_back(x)
#define pp() pop_back()
#define all(arr) arr.begin(), arr.end();
#define loop(i, n) for (int i = 0; i < n; i++)
#define xloop(a, b) for (int j = a; j <= b; j++)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)

using namespace std;

template <typename T>
T GCD(T a, T b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <typename T>
T LCM(T a, T b)
{
    return (a * b) / GCD(a, b);
}