/* Problem Statement : Given a sort data set of size N, and a key. We need to return the minimum possible difference of element with the key. [*] Finding the difference with the closest element from the key, to obtain the minimum difference.
NOTE : If Key is present in the data set, then the closest element to the key is the key itself, therefore, the minimum difference will be 0.

Sample Test Cases
3
5 12
1 3 8 10 15        
8 5
0 2 6 8 10 12 14 16
2 1
-1 0
case #1 : 2
case #2 : 1
case #3 : 1
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
/* Approach  I : Takes O(logN). Performe binary Search for ke y in the data set. Once the loop terminates, closest two values to the key are present at [low] and [high]. We can obtain the min difference of them with the key and return.
  Approach II : O(LogN) twice. We can find the ceil(key) and floor(key), then simply return the min difference resustant, i.e., min(abs(ceil(key)-key), abs(floor(key)-key));
*/
int Solve(int *data, int n, int &key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] == key)
            return 0; //absolute difference will be 0 if ket is present.
        else if (data[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    // If key is not present, Minimum Possible difference will be :
    return min(abs(data[low] - key), abs(data[high] - key));
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
        delete[] data;
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;

    return 0;
}