/* Problem Statement : The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
Sample Test Case  :
3
7 100 80 60 70 60 75 85
5 10 4 5 90 120
10 90 120 140 45 65 70 75 85 55 40
case #1 : 1,1,1,2,1,4,6,
case #2 : 1,1,2,4,5,
case #3 : 1,2,3,1,2,3,4,5,1,1,
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
/*
 Brute FORCE : O(N^2) Solution
   vector<int> res;
   for(int i=0;i<n;i++){
       int count = 0;
       for(int j=i;j>=0;j--){
           if(price[j]<=price[i]){
               count++;
           }else break;
       }
       res.push_back(count);
   }
   return res;
*/

vector<int> NGE_ToLeft(int *prices, int &n)
{
    if (n == 0)
        return {};
    v(int) res(n, -1); //resultant idx of NGE to left.
    stack<p(int, int)> st;

    st.push(make_pair(prices[0], 0));
    for (int i = 1; i < n; i++)
    {
        while (not st.empty() and st.top().first <= prices[i])
            st.pop();
        res[i] = (st.empty()) ? -1 : st.top().second;
        st.push(make_pair(prices[i], i));
    }
    return res;
}

vector<int> calculateSpan(int price[], int n)
{
    // Optimised to run in O(N) Time
    vector<int> res(n, 1);
    vector<int> indexes = NGE_ToLeft(price, n);
    for (int i = 0; i < n; i++)
    {
        res[i] = i - indexes[i];
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
        output.pb(calculateSpan(arr, n));
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