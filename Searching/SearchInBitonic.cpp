/* Problem Statement : Given an array of integers which is initially increasing and then decreasing. We need to search our target element -> Key in this Bitonic data set, and return the index. If the key is not found, it must return -1.
Sample Test Cases
3
8 7
1 3 8 9 12 7 5 2
5 97
91 93 95 97 94
10 13
5 7 9 11 13 15 17 19 21 23
case #1 : 5
case #2 : 3
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

int getMaxIndex(int *data, int &n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return (data[0] > data[1]) ? 0 : 1;

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (low == high)
            return low;
        if (low + 1 == high)
            return data[low] > data[high] ? low : high;

        if (data[mid] > data[mid + 1] and data[mid] > data[mid - 1])
            return mid;
        if (data[mid] < data[mid + 1] and data[mid] > data[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int binSearch(int *data, int low, int high, int &key, bool Order)
{
    // Order=true => ASC ORDER Data set.
    if (Order)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (data[mid] == key)
                return mid;
            else if (data[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    else //Order=false => DESC ORDER Data set.
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (data[mid] == key)
                return mid;
            else if (data[mid] < key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
}
int Solve(int *data, int &n, int &key)
{
    if (n == 0)
        return -1;
    int bitonicMaxIdx = getMaxIndex(data, n);
    // cout << bitonicMaxIdx << " \n";
    // first half -> [0 to idx] is in asc state, second half [idx+1,n-1] is int desc state.
    int idx_1 = binSearch(data, 0, bitonicMaxIdx - 1, key, true);
    int idx_2 = binSearch(data, bitonicMaxIdx, n - 1, key, false);
    return (idx_1 != -1) ? idx_1
                         : ((idx_2 != -1) ? idx_2 : -1);
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