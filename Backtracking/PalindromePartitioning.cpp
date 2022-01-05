/*
Problem Statement:
[LC 131] Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.

Sample Test Cases:
3
aab
aabb
racecar
a a b  | aa b  |
a a b b  | a a bb  | aa b b  | aa bb  |
r a c e c a r  | r a cec a r  | r aceca r  | racecar  |
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

bool isPalindrome(string str, int low, int high)
{
    while (low <= high)
    {
        if (str[low++] != str[high--])
            return false;
    }
    return true;
}
void Solve(string str, int idx, v(string) path, solutions &result)
{
    if (idx == str.size())
    {
        result.pb(path);
        return;
    }

    for (int i = idx; i < str.size(); i++)
    {
        if (isPalindrome(str, idx, i))
        {
            path.pb(str.substr(idx, i - idx + 1));
            Solve(str, i + 1, path, result);
            path.pop_back(); // backtrack
        }
    }
    return;
}
solutions partition(string str)
{
    int n = str.size();
    solutions result;
    v(string) path;

    Solve(str, 0, path, result);
    return result;
}

signed main()
{
    v(solutions) output;
    tests
    {
        string str;
        std::cin >> str;

        output.push_back(partition(str));
    }
    loop(i, output.size())
    {
        solutions soln = output[i];

        loop(j, soln.size())
        {
            loop(k, soln[j].size())
                    std::cout
                << soln[j][k] << " ";
            std::cout << " | ";
        }
        std::cout << std::endl;
    }
    return 0;
}