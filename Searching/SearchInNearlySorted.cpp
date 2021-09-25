/* Problem Statement : Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array.

Sample Test Cases
2
7 40
10 3 40 20 50 80 70
7 90
10 3 40 20 50 80 70
case #1 : 2
case #2 : NOT FOUND
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

int Solve(int *data, int &n, int &key)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] == key)
            return mid;
        if (mid > low and data[mid - 1] == key)
            return mid - 1;
        if (mid + 1 <= high and data[mid + 1] == key)
            return mid + 1;
        if (data[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
signed main()
{
    v(int) output;
    tests(t)
    {
        int n, key;
        cin >> n >> key;
        int *data = new int[n];
        input(data, n);
        output.pb(Solve(data, n, key));
    }
    loop(i, output.size())(output[i] == -1) ? (cout << "case #" << i + 1 << " : "
                                                    << "NOT FOUND\n")
                                            : cout << "case #" << i + 1 << " : " << output[i] << endl;

    return 0;
}