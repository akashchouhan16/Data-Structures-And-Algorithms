#include "headers.hpp"
/*
Sample Test Case :
3
geek eke  
apple plex 
dogs fog  
case #1 : 5
case #2 : 6
case #3 : 5
*/
int LCS(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    // init for base case -> If either of the string is null, common subsequence length will be 0.
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int shortestCommonSuperSequence(string s1, string s2, int n, int m)
{
    /*Required soln will be, worst case of merging two strings (s1 + s2), where the length will be summ og the lengths of s1 and s2, i.e. (n+m).
    since, we know there had to be a common subsequence, the common subsequence must be counted twice in teh merged string of size (n+m). Thus, we essentially need to find the longest subsequence for s1 and s2, and subtraction of the LCS(s1,s2) from the merged string length (n+m) will give us the shortest possible common supersequence.
    */
    int commonSubsequenceLength = LCS(s1, s2, n, m);
    return ((n + m) - commonSubsequenceLength);
}

int main()
{
    vi output;
    tests(t)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        output.pb(shortestCommonSuperSequence(s1, s2, n, m));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
}