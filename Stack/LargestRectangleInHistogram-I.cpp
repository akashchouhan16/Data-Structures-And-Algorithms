/*

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
class largestRectangleHistogram_I
{
protected:
    vector<datatype> heights;
    int size;
    datatype max(datatype num1, datatype num2) { return num1 > num2 ? num1 : num2; }

public:
    largestRectangleHistogram_I(int _size = 0) : size(_size) {}
    void input()
    {
        int _value = -1;
        do
        {
            std::cin >> _value;
            if (_value < 0)
                break;
            heights.pb(_value);
        } while (true);
    }
    datatype Solve();
};

template <typename datatype>
datatype largestRectangleHistogram_I<datatype>::Solve()
{
    v(datatype) left(this->size, 0), right(this->size, 0);
    stack<datatype> St;

    // Process all the left smaller indexes:
    for (int i = 0; i < size; i++)
    {
        while (not St.empty() and heights[St.top()] >= heights[i])
            St.pop();
        left[i] = St.empty() ? 0 : St.top() + 1;
        St.push(i);
    }
    // Clear the Stack to reuse for right smaller indexes.
    while (not St.empty())
        St.pop();
    for (int i = size - 1; i >= 0; i--)
    {
        while (not St.empty() and heights[St.top()] >= heights[i])
            St.pop();

        right[i] = St.empty() ? size - 1 : St.top() - 1;
        St.push(i);
    }

    datatype maxArea = 0;
    for (int i = 0; i < size; i++)
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));

    return maxArea;
}

signed main()
{
    int N;
    cin >> N;
    largestRectangleHistogram_I<int> obj(N);
    obj.input();
    std::cout << obj.Solve() << " ans\n";
    return 0;
}
