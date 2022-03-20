/* Problem Statement :
Given a sequence, find the length of the longest palindromic subsequence in it.
Approach: The idea is very straightforward. We are familiar with the approach of finding the longest possible common subsequence of two given strings. Here, we and utilize that concept on the given string and its reverse to obtain the longest possible palindromic subsequence.
Therefore, the Longest Palindromic subsequence (LPS) is nothing but the Longest Common Subsequence problem on the input string s and reverse(s).
[Note] LPS(a,n) = LCS(a,reverse(a),n); 

Sample Test Case :
3
bbbab       
helloracecar
agbcba      
case #1 : 4
case #2 : 7
case #3 : 5
*/
#include "headers.hpp"

int LCS(string, string, int);
int LPS(string s, int n)
{
    string rev = s;
    reverse(rev.begin(), rev.end());

    return LCS(s, rev, n);
}

int LCS(string a, string b, int n)
{
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}
int main()
{
    vi output;
    tests(t)
    {
        string s;
        cin >> s;
        int n = s.size();
        output.pb(LPS(s, n));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}