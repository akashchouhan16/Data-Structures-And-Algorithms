/* Problem Statement : Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array. [Array is in Bitonic State]

Sample Test Cases
4
11
8 10 20 80 100 200 400 500 3 2 1
5
10 20 30 40 50
6
97 57 42 29 25 12
7
1 3 50 10 9 7 6
case #1 : 500
case #2 : 50
case #3 : 97
case #4 : 50
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

int Solve(int *data, int &n)
{

    int low = 0, high = n - 1;
    if (n == 1)
        return data[0];

    while (low <= high)
    {
        if (low == high)
            return data[low];
        if (low + 1 == high)
            return (data[low] > data[high]) ? data[low] : data[high];
        int mid = low + (high - low) / 2;
        if (data[mid] > data[mid + 1] and data[mid] > data[mid - 1])
            return data[mid];
        else if (data[mid] > data[mid + 1] and data[mid] < data[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return INT_MIN;
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
    loop(i, output.size())(output[i] == INT_MIN) ? (cout << "case #" << i + 1 << " : "
                                                         << "NOT FOUND\n")
                                                 : cout << "case #" << i + 1 << " : " << output[i] << endl;

    return 0;
}