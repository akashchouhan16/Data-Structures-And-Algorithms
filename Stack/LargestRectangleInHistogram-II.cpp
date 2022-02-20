/* Most Optimised Solution [Tricky To Explain]
    Time: O(N) + O(N)
    Space: O(N)
Sample Test:
6
2 1 5 6 2 3 -1
10 ans
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

template <typename datatype>
class LargestRectangleHistogram_II
{
protected:
    vector<datatype> heights;
    int size;
    datatype max(datatype num1, datatype num2) { return num1 > num2 ? num1 : num2; }

public:
    LargestRectangleHistogram_II(int _size = 0) : size(_size) {}
    void input()
    {
        datatype _value = -1;
        do
        {
            std::cin >> _value;
            if (_value < 0)
                break;

            heights.pb(_value);
        } while (true);
        this->size = heights.size();
    }
    datatype Solve();
};
template <typename datatype>
datatype LargestRectangleHistogram_II<datatype>::Solve()
{
    datatype maxArea = 0;
    stack<datatype> St;
    int N = this->size;

    for (int i = 0; i < N; i++)
    {
        while (not St.empty() and (i == N || heights[St.top()] >= heights[i]))
        {
            int height = heights[St.top()];
            St.pop();
            int width = St.empty() ? i : i - St.top() - 1;

            maxArea = max(maxArea, (width * height));
        }
        St.push(i);
    }
    return maxArea;
}

signed main()
{
    int N;
    cin >> N;
    LargestRectangleHistogram_II<int> obj(N);
    obj.input();
    std::cout << obj.Solve() << " ans\n";
    return 0;
}