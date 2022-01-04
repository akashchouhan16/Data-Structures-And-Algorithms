/*
Sample Test Case:
2
ABC
EFGH
Case #1:  | A | AB | ABC | AC | B | BC | C |
Case #2:  | E | EF | EFG | EFGH | EFH | EG | EGH | EH | F | FG | FGH | FH | G | GH | H | 
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define INF2 INT_MIN
#define ll long long
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define ff first
#define ss second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define pp() pop_back()
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

#define tests \
    int t;    \
    cin >> t; \
    while (t--)

void Solve(int start, int len, string str, set<string> &set, string curr = "")
{
    if (start == len)
    {
        set.insert(curr);
        return;
    }
    Solve(start + 1, len, str, set, curr);
    curr.pb(str[start]);
    Solve(start + 1, len, str, set, curr);
    return;
}
v(string) allSubsets(string str)
{
    int n = str.size();

    v(string) OUTPUT;
    set<string> set;
    Solve(0, n, str, set);
    for (auto it = set.begin(); it != set.end(); it++)
    {
        OUTPUT.pb(*it);
    }
    return OUTPUT;
}
signed main()
{
    v(v(string)) out;
    tests
    {
        string str;
        cin >> str;
        out.pb(allSubsets(str));
    }

    loop(i, out.size())
    {
        cout << "Case #" << i + 1 << ": ";
        v(string) ans = out[i];
        loop(i, ans.size())
        {
            cout << ans[i] << " | ";
        }
        cout << endl;
    }
    return 0;
}
