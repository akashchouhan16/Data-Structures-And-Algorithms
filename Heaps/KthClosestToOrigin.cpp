/*
Sample Test Cases:
3
2 3 1 5 -1 -2 4 99 99
1 -2 2 1 3 99 99
3 4 2 -3 5 1 2 -2 4 5 1 99 99

OUTPUT:
[3,1], [-2,4],
[-2,2],
[1,2], [4,2], [-2,4],
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF 99 // temporary max.
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

struct point
{
    int x, y;
};

class KthClosestToOrigin
{
    v(point) points;
    v(point) output;
    int K;

public:
    KthClosestToOrigin(int _k) : K(_k) { input(); }
    void input()
    {
        point pt = {INF, INF};
        do
        {
            std::cin >> pt.x >> pt.y;
            if (pt.x == INF or pt.y == INF)
                break;
            points.pb(pt);
        } while (pt.x != INF or pt.y != INF);
    }
    void solve();
    v(point) get_results();
};

void KthClosestToOrigin::solve()
{
    map<int, vector<point>> _mp;
    for (auto pt : points)
    {
        int distance = pt.x * pt.x + pt.y * pt.y;
        _mp[distance].push_back(pt);
    }

    for (auto x : _mp)
    {
        for (auto pt : x.second)
        {
            if (this->output.size() == K)
                return;
            output.push_back(pt);
        }
    }
    return;
}
inline v(point) KthClosestToOrigin::get_results() { return this->output; }

signed main()
{
    v(v(point)) output;
    tests
    {
        int k;
        std::cin >> k;
        KthClosestToOrigin obj(k);

        obj.solve();
        output.push_back(obj.get_results());
    }

    loop(i, output.size())
    {
        v(point) ans = output[i];
        loop(j, ans.size()) std::cout << "[" << ans[j].x << "," << ans[j].y << "], ";

        std::cout << std::endl;
    }
    return 0;
}