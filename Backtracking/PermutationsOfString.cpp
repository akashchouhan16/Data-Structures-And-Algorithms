/*Sample Test Case:
3
test 
ABC
OT
Case #1: estt | etst | etts | sett | stet | stte | test | tets | tset | tste | ttes | ttse | 
Case #2: ABC | ACB | BAC | BCA | CAB | CBA |
Case #3: OT | TO |
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

inline void swap(char &ch1, char &ch2)
{
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

void Solve(int pos, int len, string str, set<string> &set)
{
    if (pos == len)
    {
        set.insert(str);
        return;
    }
    for (int i = pos; i < len; i++)
    {
        swap(str[pos], str[i]);
        Solve(pos + 1, len, str, set);
        swap(str[pos], str[i]);
    }
    return;
}
v(string) permutations(string str)
{
    int n = str.size();
    if (not n)
        return {};

    set<string> set;
    Solve(0, n, str, set);
    v(string) output;
    for (auto it = set.begin(); it != set.end(); it++)
    {
        output.pb(*it);
    }
    return output;
}
signed main()
{
    v(v(string)) out;
    tests
    {
        string str;
        cin >> str;
        out.pb(permutations(str));
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