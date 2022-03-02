/*
Problem Statement: Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.
Sample Test Cases:
3
a1b2
3z4
56aBz5

OUTPUT:
A1B2, A1b2, a1B2, a1b2,
3Z4, 3z4,
56AbZ5, 56Abz5, 56ABZ5, 56ABz5, 56abZ5, 56abz5, 56aBZ5, 56aBz5,
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define INF2 INT_MIN
#define ll long long
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define ff first
#define ss second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define pp() pop_back()
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

#define solutions v(v(string)) // temporary.
#define tests \
    int t;    \
    cin >> t; \
    while (t--)

void Solve(string str, int index, v(string) & solution)
{
    if (index == str.size() + 1)
        return;
    if (index == str.size())
    {
        solution.pb(str);
        return;
    }

    if (str[index] >= 'a' and str[index] <= 'z')
    {
        str[index] -= 32;
        Solve(str, index + 1, solution);
        str[index] += 32;
        Solve(str, index + 1, solution);
    }
    else if (str[index] >= 'A' and str[index] <= 'Z')
    {
        str[index] += 32;
        Solve(str, index + 1, solution);
        str[index] -= 32;
        Solve(str, index + 1, solution);
    }
    else
        Solve(str, index + 1, solution);
    return;
}
v(string) generateLetterCasePermutations(string str)
{
    v(string) solution;
    Solve(str, 0, solution);
    return solution;
}
signed main()
{
    vector<v(string)> output;
    tests
    {
        string str;
        cin >> str;
        output.pb(generateLetterCasePermutations(str));
    }

    for (auto soln : output)
    {
        for (auto str : soln)
        {
            cout << str << ", ";
        }
        cout << endl;
    }
    return 0;
}