/*Problem Statement : Design a Data Structure SpecialStack that supports all the stack operations like push(), pop() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure

Sample Test Case : 
1 [Static input]
case #1 : null
case #2 : null
case #3 : null
case #4 : 0   
case #5 : null
case #6 : 0 
*/

#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>

#define MOD 1e9 + 7
#define ll long long
#define int ll
#define loop(i, n) for (int i = 0; i < n; i++)
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define pb(x) push_back(x)
#define pp() pop_back()
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)

using namespace std;

class MinStack
{
public:
    stack<int> st;
    stack<int> temp; //supporting stack.
    MinStack() {}

    string push(int val)
    {
        st.push(val);
        if (temp.empty())
            temp.push(val);
        else if (val <= temp.top())
            temp.push(val);
        return "null";
    }

    string pop()
    {
        int val = st.top();
        if (val == temp.top())
            temp.pop();
        st.pop();
        return "null";
    }

    string top()
    {
        if (st.empty())
            return to_string(-1);
        return to_string(st.top());
    }

    string getMin()
    {
        if (temp.empty())
            return to_string(-1);
        else
            return to_string(temp.top());
    }
};

signed main()
{
    v(string) output;
    tests(t)
    {
        MinStack instance;
        output.push_back(instance.push(0));
        output.push_back(instance.push(1));
        output.push_back(instance.push(0));
        output.push_back(instance.getMin());
        output.push_back(instance.pop());
        output.push_back(instance.getMin());
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}