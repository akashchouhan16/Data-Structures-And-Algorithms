/*Problem Statement: Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
You may return the answer in any order.

Sample Test Cases:
3
4 2
5 3
1 1
OUTPUT:
1, 2,
1, 3,
2, 3,
1, 4,
2, 4,
3, 4,
1, 2, 3,
1, 2, 4,
1, 3, 4,
2, 3, 4,
1, 2, 5,
1, 3, 5,
2, 3, 5,
1, 4, 5,
2, 4, 5,
3, 4, 5,
1
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

#define solutions v(v(string)) // temporary.
#define tests \
    int t;    \
    cin >> t; \
    while (t--)

v(v(int)) generatePowerSet(v(int) & values, int size)
{
    v(v(int)) powerSet;
    powerSet.pb({});

    for (auto value : values)
    {
        int n = powerSet.size();
        for (int i = 0; i < n; i++)
        {
            v(int) temp = powerSet[i];
            temp.pb(value);
            powerSet.pb(temp);
        }
    }
    return powerSet;
}
v(v(int)) combinations(int N, int K)
{
    // Idea: To generate the power set for vector containing elements [1 to N]. Desired output will contain all the power set elements that are sized K.
    if (N < K)
        return {};
    v(int) values(N, 1);
    for (int i = 1; i < N; i++)
        values[i] = i + 1;

    vector<v(int)> powerSet = generatePowerSet(values, N);
    v(v(int)) result;
    for (auto _set : powerSet)
        if (_set.size() == K)
            result.pb(_set);

    return result;
}
signed main()
{
    v(v(v(int))) outputs;
    tests
    {
        int N, K;
        cin >> N >> K;
        outputs.pb(combinations(N, K));
    }

    for (auto output : outputs)
    {
        for (auto vec : output)
        {
            for (int i = 0; i < vec.size(); i++)
                cout << vec[i] << ", ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}