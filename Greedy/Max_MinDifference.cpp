/* Problem Statement : WE are given an array of n elements. We need to remove exactly n/2 elements to another another. just that we can find the maximum and minimum value difference between the ith corresponding elements of the two arrays.
NOTE : value difference => summation of abs(array1[i] - array2[i])
the value difference has to be maximized and minimized.
Sample Test Case :
i/p : 4             o/p : Min = 5, Max = 25
     12 -3 10 0
Approach : 1.Sort the Array (asc) | 2. Max diff = (sum of last n/2 elements) - (sum of first n/2 elements)
                                      Min Diff = (sum of all odd pos elements) - (sum of all even pos elements)
*/
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define pb(x) push_back(x);
#define pp() pop_back()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pqq priority_queue
#define gi greater<int>
#define all(arr) arr.begin(), arr.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define MOD ll(1e9 + 7)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
using namespace std;
inline void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Solve(vi &array, int n, int &min, int &max)
{
    sort(all(array));
    int tempMax = 0, tempMin = 0;
    loop(i, n / 2)
    {
        max += (array[i + n / 2] - array[i]);
        min += (array[2 * i + 1] - array[2 * i]);
    }
    return;

    // for (int i = n - 1; i >= n / 2; i--)
    //     tempMax += (array[i]);
    // for (int i = 0; i < n / 2; i++)
    //     tempMin += array[i];
    // max = (tempMax - tempMin);

    // tempMax = 0, tempMin = 0; //reset
    // loop(i, n)
    // {
    //     (i & 1) ? (tempMax += array[i]) : (tempMin += array[i]);
    // }
    // min = abs(tempMax - tempMin);
    return;
}
int main()
{
    IOS();
    tests(t)
    {
        int n;
        cin >> n;
        vi array;
        loop(i, n)
        {
            int x;
            cin >> x;
            array.pb(x);
        }
        int min = 0, max = 0;
        Solve(array, n, min, max);
        cout << "Min = " << min << "\nMax = " << max << endl;
    }
    return 0;
}