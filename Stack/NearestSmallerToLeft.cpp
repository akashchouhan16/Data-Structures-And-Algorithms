/*Problem Statement : Given an array of integers, find the closest (not considering distance, but value) smaller on left of every element. If an element has no smaller on the left side, print -1.

Sample Test Case : 
4
5
1 3 0 2 5
6
1 6 4 10 2 5
7
4 7 5 9 2 3 10
3 5 2 7
case #1 : -1,1,-1,0,2,
case #2 : -1,1,1,4,1,2,
case #3 : -1,4,4,5,-1,2,3,
case #4 : -1,-1,2,
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

vector<int> nearestSmalleerToLeft(int *arr, int &n)
{
    if (n == 0)
        return {};
    vector<int> res(n, -1);
    stack<int> st;
    st.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and st.top() >= arr[i])
            st.pop();
        if (st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
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
        output.pb(nearestSmalleerToLeft(arr, n));
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