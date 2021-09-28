/*Problem Statement : Given an array of integers, find the closest (not considering distance, but value) greater on left of every element. If an element has no greater on the left side, print -1.

Sample Test Case : 
3
4 1 3 2 4
7 4 7 5 9 10 8 3
3 3 3 3
case #1 : -1,-1,3,-1,
case #2 : -1,-1,7,-1,-1,10,8,
case #3 : -1,-1,-1,
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
/* Brute Force : Pseudo
    vector<int> soln(n,-1);
    for (int i = 1; i < n; i++)
    {
        bool changed = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                changed = true;
                soln[i] = arr[j];
                break;
            }
        }
        if (!changed) soln[i] = -1;
    }
    return soln;
*/
vector<int> nearestGreaterToLeft(int *arr, int &n)
{
    if (n == 0)
        return {};
    vector<int> res(n, -1);
    stack<int> st;
    st.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and st.top() <= arr[i])
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
        output.pb(nearestGreaterToLeft(arr, n));
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