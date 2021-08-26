#include "headers.hpp"
/* Problem Statement: Given a string, print the longest repeating subsequence such that the two subsequences don’t have the same string character at the same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
The two subsequences are 'a'(first) and 'a' (second). Note that 'b' cannot be considered as part of subsequence as it would be at the same
index in both.

Sample Test Case :
3
AABEBCDD
ABCDDBC
eloeggogll
case #1 : 3
case #2 : 2
case #3 : 4
*/
int longestRepeatingSubsequence(string s1, int n)
{
    string s2 = s1;

    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        dp[0][i] = dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1] and (i != j))
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
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
        output.pb(longestRepeatingSubsequence(s, n));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}