#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
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
// O(|S|) Solution :
template <typename T>
inline T min(T &a, T &b) { return (a < b) ? a : b; }

ll Solve(v(string) & S, string word1, string word2)
{
    int n = S.size();
    if (n == 0)
        return -1;

    ll minDist = LONG_LONG_MAX;
    int idx2 = -1, i = n - 1;
    while (i >= 0)
    {
        if (S[i] == word2)
        {
            idx2 = i;
        }
        if (S[i] == word1 and idx2 != -1)
        {
            minDist = min<ll>(minDist, abs(idx2 - i));
        }
        i--;
    }
    return minDist;
}
signed main()
{
    v(ll) out;
    tests
    {
        v(string) S;
        string str = "";
        while (str != "-1")
        {
            cin >> str;
            if (str == "-1")
            {
                cout << "[*] Input complete.\n";
                break;
            }
            S.pb(str);
        }

        string word1, word2;
        cin >> word1 >> word2;
        // fflush(stdin);
        out.pb(Solve(S, word1, word2));
    }

    loop(i, out.size()) cout << out[i] << endl;
    return 0;
}