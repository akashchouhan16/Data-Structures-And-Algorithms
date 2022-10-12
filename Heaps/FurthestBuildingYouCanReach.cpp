/*
Sample Test Cases:
3
10 2 4 12 2 7 3 18 20 3 19 -1
17 0 14 3 19 3 -1
5 1 4 2 7 6 9 14 12 -1

OUTPUT:
7 3 4
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
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

class FurthestBuildingToReach
{
    v(int) heights;
    int bricks, ladders;
    int furthest_building;

public:
    FurthestBuildingToReach(int _bricks = 0, int _ladders = 0) : bricks(_bricks), ladders(_ladders)
    {
        this->furthest_building = 0;
        input();
    }
    void input()
    {
        int height = -1;
        do
        {
            std::cin >> height;
            if (height < 0)
                break;
            heights.pb(height);
        } while (height != -1);
    }
    void solve();
    int get_results();
};

void FurthestBuildingToReach::solve()
{
    priority_queue<int> maxHeap;
    for (int i = 1; i < heights.size(); i++)
    {
        int difference = heights[i] - heights[i - 1];
        if (difference > 0)
        {
            bricks -= difference;
            maxHeap.push(difference);

            if (bricks < 0)
            {
                bricks += maxHeap.top();
                ladders--;

                if (bricks < 0 or ladders < 0)
                {
                    this->furthest_building = i - 1;
                    return;
                }
            }
        }
    }
    this->furthest_building = heights.size() - 1;
    return;
}
inline int FurthestBuildingToReach::get_results() { return this->furthest_building; }

signed main()
{
    v(int) output;
    tests
    {
        int bricks, ladders;
        std::cin >> bricks >> ladders;

        FurthestBuildingToReach obj(bricks, ladders);
        obj.solve();

        output.pb(obj.get_results());
    }

    loop(i, output.size()) std::cout << output[i] << " ";
    std::cout << std::endl;
    return 0;
}