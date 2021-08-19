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

void Solve(vector<pii> &jobs, int n, int &noOfJobs, int &maxProfit)
{
    sort(all(jobs), greater<pii>()); //sorted based on max profit -> min profit.
    vector<int> slots(n, -1);
    int res = 0;
    loop(i, n)
    {
        pii temp = jobs[i];
        int x = 0, deadline = temp.second;
        while (x < deadline)
        {
            if (slots[x] == -1)
            {
                res += temp.first;
                slots[x] = 1; //job scheduled.
                break;
            }
            x++;
        }
        maxProfit = (maxProfit < res) ? res : maxProfit;
    }
    int x = -1;
    while (++x < n)
    {
        if (slots[x] != -1)
            noOfJobs++;
    }
    return;
}

int main()
{
    // IOS();
    tests(t)
    {
        cout << "Number of jobs (n) | <profit,deadline>\n";
        int n;
        cin >> n;
        vector<pii> jobs;
        loop(i, n)
        {
            int deadline, profit;
            cin >> profit >> deadline;
            jobs.push_back(make_pair(profit, deadline));
        }

        int noOfJobs = 0, maxProfit = 0;
        Solve(jobs, n, noOfJobs, maxProfit);
        cout << "No of Jobs Performed : " << noOfJobs << endl
             << "Max Profit : " << maxProfit << endl;
    }

    return 0;
}