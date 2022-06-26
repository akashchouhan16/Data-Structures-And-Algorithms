/* Problem Statement: Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Sample Test:
Input:1
5 3
1 2 8 4 9
OUTPUT: 3
*/

#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define pb(x) push_back(x)
#define pp() pop_back();
#define all(x) x.begin(), x.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(a, b) for (int i = a; i <= b; i++)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)

using namespace std;

bool canPlaceCows(v(ll) & positions, ll &N, ll &cows, ll &distance)
{
    ll position = positions[0];
    ll count = 1;

    for (int i = 1; i < N; i++)
    {
        if (positions[i] - position >= distance)
        {
            count++;
            position = positions[i];
        }
        if (count == cows)
            return true;
    }

    return false;
}

ll Solve(v(ll) & positions, ll &N, ll &cows)
{
    std::sort(all(positions));
    ll low = 1, high = positions[N - 1] - positions[0];

    ll answer = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (canPlaceCows(positions, N, cows, mid))
        {
            answer = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return answer;
}

signed main()
{

    v(ll) output;
    tests(t)
    {
        ll N, cows;
        cin >> N >> cows;
        v(ll) positions(N, -1);

        for (ll i = 0; i < N; i++)
            cin >> positions[i];

        output.pb(Solve(positions, N, cows));
    }

    for (ll x : output)
        cout << x << "\n";

    return 0;
}