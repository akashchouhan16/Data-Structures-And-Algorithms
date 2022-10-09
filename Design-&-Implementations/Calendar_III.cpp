/*
Problem Statement: A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events). You are given some events [start, end), after each given event, return an integer k representing the maximum k-booking between all the previous events.

Sample LC Input:
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]

Sample LC Output:
[null, 1, 1, 2, 3, 3, 3]
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
    int max_bookings;

public:
    Calendar() : max_bookings(0) {}
    int book(int startDate, int endDate)
    {
        calendar[startDate]++;
        calendar[endDate]--;
        int current_bookings = 0;
        for (auto booking : calendar)
        {
            current_bookings += booking.second;
            max_bookings = max(max_bookings, current_bookings);
        }

        return max_bookings;
    }
};

signed main()
{
    v(int) output;
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

    for (int k : output)
        cout << k << " ";
    cout << endl;
    return 0;
}