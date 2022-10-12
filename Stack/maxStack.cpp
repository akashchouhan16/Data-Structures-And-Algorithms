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

template <typename type>
class maxStack
{
protected:
    stack<pair<type, type>> St;

public:
    maxStack()
    {
        St.push(make_pair(-1, INT_MIN));
    }
    void displayStack()
    {
        if (St.size() == 1)
            return;
        pair<type, type> element = St.top();
        St.pop();
        std::cout << element.first << " " << element.second << std::endl;
        displayStack();
        St.push(element);
        return;
    }
    void push(type);
    type pop();
    type getMax();
};

template <typename type>
inline type maxStack<type>::getMax()
{
    return St.size() <= 1 ? type(-1) : St.top().second;
}
template <typename type>
inline type maxStack<type>::pop()
{
    if (St.size() <= 1)
        return type(-1);
    else
    {
        type element = St.top().first;
        St.pop();
        return element;
    }
}
template <typename type>
inline void maxStack<type>::push(type value)
{
    int maxValue = St.top().second < value ? value : St.top().second;
    St.push(make_pair(value, maxValue));
    return;
}
signed main()
{
    maxStack<long> object;
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