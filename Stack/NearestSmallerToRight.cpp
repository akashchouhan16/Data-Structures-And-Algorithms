/*Problem Statement : Given an array of integers, find the closest (not considering distance, but value) smaller on right of every element. If an element has no smaller on the right side, print -1.

Sample Test Case : 
4
5 4 5 2 10 8
7 1 3 0 0 1 2 4
4 1 3 2 4
10 2 5 8 6 1 7 9 3 4 0
case #1 : 2,2,-1,8,-1,
case #2 : 0,0,-1,-1,-1,-1,-1,
case #3 : -1,2,-1,-1,
case #4 : 1,1,6,1,0,3,3,0,0,-1,
*/
#include <bits/stdc++.h>
#include <algorithm>

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

void input(int *arr, int &n)
{
    loop(i, n) cin >> arr[i];
    return;
}

vector<int> nearestSmalleerToRight(int *arr, int &n)
{
    if (n == 0)
        return {};
    vector<int> res(n, -1);
    stack<int> st;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (not st.empty() and st.top() >= arr[i])
            st.pop();
        res[i] = (st.empty()) ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}
signed main()
{
    vector<v(int)> output;
    tests(t)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        input(arr, n);
        output.pb(nearestSmalleerToRight(arr, n));
        delete[] arr;
    }

    loop(i, output.size())
    {
        cout << "case #" << i + 1 << " : ";
        vector<int> temp = output[i];
        loop(j, temp.size()) cout << temp[j] << ",";
        cout << endl;
    }
    return 0;
}