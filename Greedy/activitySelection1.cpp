/* Classical Activity Selection Problem : 
we will be provided with n activities with their corresponding start and end times. We need to what will be
the maximum number of activities that can be performed. Note, we cannot perform two or more activities simultaneously.
Sample Test Case : 
i/p : 3         o/p : 2 activites.
    10 20
    12 15
    20 30
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define ll long long
#define pb(x) push_back(x);
#define pp() pop_back()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pqq priority_queue
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

int main()
{
    IOS();
    tests(t)
    {
        int n;
        cin >> n;
        vector<vi> activity;
        loop(i, n)
        {
            int startTime, endTime;
            cin >> startTime >> endTime;
            activity.push_back({startTime, endTime});
        }
        //sorting activities based on the end times
        sort(activity.begin(), activity.end(), [&](vi &a, vi &b)
             { return (a[1] < b[1]); });

        int count = 1;
        int end = activity[0][1];
        for (int i = 1; i < n; i++)
        {
            if (activity[i][0] >= end)
            {
                count++;
                end = activity[i][1];
            }
        }
        cout << count << " activities.\n";
    }
    return 0;
}
