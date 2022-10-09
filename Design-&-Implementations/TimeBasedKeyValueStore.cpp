/*
Problem Statement: Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Sample LC Input: ["TimeMap","set","get","get","set","get","get"]
[[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]

Sample LC Output:

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

class TimeValueStore
{
    map<string, map<int, string>> lookUpTable;

public:
    TimeValueStore() {}
    // Exposed APIs
    void set(string, string, int);
    string get(string, int);
};

// Implementation:
void TimeValueStore::set(string key, string value, int timestamp)
{
    lookUpTable[key][timestamp] = value;
    return;
}
string TimeValueStore::get(string key, int timestamp)
{
    for (int time = timestamp; time >= 1; time--)
    {
        if (lookUpTable[key][time] != "")
            return lookUpTable[key][time];
    }
    return "";
}
signed main()
{
    v(string) output;
    tests
    {
        TimeValueStore *store = new TimeValueStore();
        store->set("foo", "bar", 1);
        output.push_back(store->get("foo", 1));
        output.push_back(store->get("foo", 3));
        store->set("foo", "bar2", 4);
        output.push_back(store->get("foo", 4));
        output.push_back(store->get("foo", 5));
    }

    for (string answer : output)
        cout << answer << " ";
    cout << endl;
    return 0;
}