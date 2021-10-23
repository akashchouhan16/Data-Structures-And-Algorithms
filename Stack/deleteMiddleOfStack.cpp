/* Problem Statement: Stack Based <Easy>. Given a Stack, delete the middle element of the stack without using additional stack or queue.

Sample Test Case:
3
1 2 3 4 5 6 7 -1
113 115 117 118 119 212 213 241 251 231 -1
71 45 67 81 2 91 -1
Case #1: 1 2 3 5 6 7
Case #2: 113 115 117 118 212 213 241 251 231
Case #3: 71 45 81 2 91
*/
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

inline void input(stack<int> &St)
{
    int _val = -1;
    do
    {
        cin >> _val;
        if (_val <= -1)
            break;
        St.push(_val);
    } while (true);
    return;
}

void deleteMiddleElement(stack<int> &St, ll N, ll curr)
{
    if (St.empty() or curr == N)
        return;
    int st_data = St.top();
    St.pop();
    deleteMiddleElement(St, N, curr + 1);
    if (curr != N / 2)
        St.push(st_data);
    return;
}
v(ll) Solve(stack<int> &St, ll N)
{
    v(ll) output;
    deleteMiddleElement(St, N, 0);

    while (not St.empty())
    {
        output.pb(St.top());
        St.pop();
    }
    reverse(all(output));
    return output;
}
signed main()
{
    v(v(ll)) out;
    tests
    {
        stack<int> St;
        input(St);
        ll N = St.size();

        out.pb(Solve(St, N));
    }

    loop(i, out.size())
    {
        v(ll) data = out[i];
        cout << "Case #" << i + 1 << ": ";
        loop(j, data.size())
                cout
            << data[j] << " ";
        cout << endl;
    }
    return 0;
}