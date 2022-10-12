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

class minStack
{
protected:
    stack<p(int, int)> St;

public:
    minStack()
    {
        St.push(make_pair(-1, INT_MAX));
    }
    void push(int value);
    int pop();
    int getMin();
    // For Debugging Purpose:
    void displayStack();
};
inline void minStack::push(int value)
{
    int minValue = value < St.top().second ? value : St.top().second;
    St.push(make_pair(value, minValue));
    return;
}
inline int minStack::pop()
{
    if (St.size() <= 1)
        return -1;
    int element = St.top().first;
    St.pop();
    return element;
}
inline int minStack::getMin()
{
    return St.size() > 1 ? St.top().second : -1;
}
void minStack::displayStack()
{
    if (St.size() == 1)
        return;
    p(int, int) element = St.top();
    St.pop();
    std::cout << element.first << " " << element.second << "\n";
    displayStack();
    St.push(element);
    return;
}

signed main()
{
    // Test Custom Inputs.
    minStack object;
    object.push(5);
    object.push(3);
    object.push(9);
    object.push(4);
    object.push(1);
    object.push(7);
    object.displayStack();
    cout << endl;
    object.pop();
    object.push(2);
    object.displayStack();
    cout << endl;
    object.pop();
    object.pop();
    object.push(2);
    object.displayStack();
    cout << endl;
    object.pop();
    object.pop();
    object.displayStack();
    cout << endl;
    return 0;
}