/* Problem Statement : Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour.

Sample Test Cases
3
7
10 20 15 2 23 90 67       
1
17
5
1 3 5 7 9
case #1 : 1
case #2 : 0
case #3 : 4
*/
#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define pb(x) push_back(x)
#define pp() pop_back();
#define all(x) x.begin(), x.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(a, b) for (int i = a; i <= b; i++)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)

using namespace std;

void input(int *data, int &n)
{
    loop(i, n)
    {
        cin >> data[i];
    }
}
void display(int *data, int &n)
{
    loop(i, n)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return;
}

int getPeakIndex(int *data, int low, int high, int &n)
{
    int mid = low + (high - low) / 2;
    if ((mid == 0 or data[mid - 1] <= data[mid]) and (mid == n - 1 or data[mid + 1] <= data[mid]))
        return mid;
    if (mid > 0 and data[mid - 1] > data[mid])
        return getPeakIndex(data, low, mid - 1, n);
    else
        return getPeakIndex(data, mid + 1, high, n);
    return -1;
}
int Solve(int *data, int n)
{
    int idx = -1;
    if (n == 0)
        return idx;
    idx = getPeakIndex(data, 0, n - 1, n); //O(LogN) Solution.
    return idx;
}

signed main()
{
    v(int) output;
    tests(t)
    {
        int n;
        cin >> n;
        int *data = new int[n];
        input(data, n);
        output.pb(Solve(data, n));
    }
    loop(i, output.size())(output[i] == -1) ? (cout << "case #" << i + 1 << " : "
                                                    << "NOT FOUND\n")
                                            : cout << "case #" << i + 1 << " : " << output[i] << endl;

    return 0;
}