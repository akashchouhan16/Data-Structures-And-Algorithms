/* Problem Statement : Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

Input: n = 6                                        Input: n = 3                                                    
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}            arr[] = {0900, 1100, 1235}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}            dep[] = {1000, 1200, 1240}
Output: 3                                           Output: 1
// APPROACH 1 : O(NlogN) time and O(N) Space using minHeap (Greedy)
We add elements to minHeap based on the end time and their platform count <endTime,count>
// APPROACH 2 : O(NlogN) Time and O(1) Space solution using two pointer + Greedy
*/
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define pb(x) push_back(x);
#define pp() pop_back()
#define vi vector<int>
#define v(x) vector<x>
#define pii pair<int, int>
#define pqq priority_queue
#define g(x) greater<x>
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

// Solution 1 :
int PlatformCount(int n, vi &arrival, vi &depart)
{
    if (n == 0) //no train arrives/departs
        return 0;
    pqq<pii, v(pii), g(pii)> minHeap;
    sort(all(depart));
    minHeap.push({depart[0], 1});
    int count = 1; //platform count.
    for (int i = 1; i < n; i++)
    {
        pii temp = minHeap.top();
        minHeap.pop();
        if (arrival[i] > temp.first)
        {
            minHeap.push({depart[i], temp.second});
        }
        else
        {
            minHeap.push({depart[i], temp.second + 1});
        }
    }
    while (!minHeap.empty())
    {
        pii t = minHeap.top();
        count = (count < t.second) ? t.second : count;
        minHeap.pop();
    }
    return count;
}

// Solution 2 :
int OptimisedSoln(int n, vi &arrival, vi &depart)
{
    sort(all(arrival));
    sort(all(depart));
    int i = 1, j = 0;
    int platformCount = 1;

    while (i < n)
    {
        if (arrival[i] <= depart[j])
            platformCount++;
        else
            j++;

        i++;
    }
    return platformCount;
}

int main()
{
    // IOS();
    tests(t)
    {
        int n;
        cout << "Enter n : ";
        cin >> n;
        vi arrival, depart;
        cout << "Enter arrival times : ";
        loop(i, n)
        {
            int x;
            cin >> x;
            arrival.pb(x);
        }
        cout << "Enter departure times : ";
        loop(i, n)
        {
            int x;
            cin >> x;
            depart.pb(x);
        }
        cout << "Min Number of Platform required : " << OptimisedSoln(n, arrival, depart) << endl;
    }

    return 0;
}
