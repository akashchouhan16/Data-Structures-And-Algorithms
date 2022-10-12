/*
Problem Statement: You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking. A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events). The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Sample LC Input:
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]

Sample LC Output:
[null, true, true, true, false, true, true]
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define nullptr NULL
#define ff first
#define ss second
#define ll long long
#define lb long double
#define g(x) greater<x>
#define loop(i, n) for (int i = 0; i < n; i++)
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define mp make_pair
#define pb(x) push_back(x)
#define pp() pop_back()
#define all(x) x.begin(), x.end()
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

class Calendar
{
    map<int, int> calendar;

public:
    Calendar() {}
    int book(int startDate, int endDate)
    {
        calendar[startDate]++;
        calendar[endDate]--;
        int bookings = 0;
        for (auto booking : calendar)
        {
            bookings += booking.second;
            if (bookings > 2)
            {
                calendar[startDate]--;
                calendar[endDate]++;
                return false;
            }
        }
        return true;
    }
};

signed main()
{
    v(bool) output;
    tests
    {
        Calendar *calendar = new Calendar();
        output.push_back(calendar->book(10, 20));
        output.push_back(calendar->book(50, 60));
        output.push_back(calendar->book(10, 40));
        output.push_back(calendar->book(5, 15));
        output.push_back(calendar->book(5, 10));
        output.push_back(calendar->book(25, 55));
    }

    for (bool k : output)
        cout << (k ? "true" : "false") << " ";
    cout << endl;
    return 0;
}