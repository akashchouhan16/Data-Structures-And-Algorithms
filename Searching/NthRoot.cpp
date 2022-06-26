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
double multiply(double &number, ll &N)
{
    double result = 1;
    for (ll i = 0; i < N; i++)
        result *= number;

    return result;
}

double Solve(ll &N, ll &num)
{
    double low = 1.0, high = num;
    double epsilon = 1e-5; // upto how many decimal places is asked in the problem statement = 5 decimal accuracy.

    while ((high - low) > epsilon)
    {
        double mid = low + (high - low) / 2.0;
        if (multiply(mid, N) < num)
            low = mid;
        else
            high = mid;
    }

    return low; // or high.
}

signed main()
{
    v(double) output;
    tests(t)
    {
        ll N, num;
        cin >> num >> N;

        output.pb(Solve(N, num));
    }

    for (double x : output)
        cout << x << "\n";

    return 0;
}