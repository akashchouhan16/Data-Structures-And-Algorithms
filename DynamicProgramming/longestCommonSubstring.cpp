#include "headers.hpp"

/*
Longest Common Substring is a variation of the LCS problem.
We need to discard all the non continuous cases in LCS, by simply reset the dp[i][j] value to 0 whenever
string1[i-1] becomes  != string2[j-1]. That is the only minor change to obtain the soln for substrings.

Sample Test Case : 
2
abedfhr xbedgfr
xcytur xtuewr
case #1 : 3
case #2 : 2
*/
int longestCommonSubstring(string S1, string S2, int n, int m)
{
    int dp[n + 1][m + 1];

    // Init the dp for base case -> n==0 || m==0 must return 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int answer = INT_MIN + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = (1 + dp[i - 1][j - 1]);
                answer = max(answer, dp[i][j]);
            }
            else
            {
                // uncommon characters encountered, hence dp[i][j] has to be reset to 0;
                dp[i][j] = 0;
            }
        }
    }
    return answer;
}
int main()
{
    vi output;
    tests(t)
    {
        string str1, str2;
        cin >> str1 >> str2;
        int n = str1.size(), m = str2.size();

        output.pb(longestCommonSubstring(str1, str2, n, m));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}