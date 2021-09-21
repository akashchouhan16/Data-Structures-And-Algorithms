/*Problem Statement : Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.
Sample Test Cases
3
5 3
2 4
3 2
case #1 : 180
case #2 : 16
case #3 : 6
*/
#include "headers.hpp"
#define mod int(1e9 + 7)

using namespace std;

ll countWays(int n, int k)
{
    if (n <= 0)
        return 0;
    if (n == k)
        return k;
    // for two poles : same -> k ways, difference -> k*(k-1) ways
    ll same = k % mod;
    ll diff = (k * (k - 1)) % mod;

    for (int i = 3; i <= n; i++)
    {
        ll prevDiff = diff % mod;
        diff = ((same + diff) * (k - 1)) % mod;
        same = prevDiff % mod;
    }

    return (same + diff) % mod;
}
int main()
{
    v(ll) output;
    tests(t)
    {
        int n, k;
        cin >> n >> k;
        output.pb(countWays(n, k));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}