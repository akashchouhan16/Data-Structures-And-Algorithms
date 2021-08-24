/* Problem Statement: We are given two strings, a and b. We need to write a function to check if string a exists as a subsequence of string b.

[Note] A subsequence of a string is a string where the order of the characters is preserved, but it can be at discontinuous positions. For example, If HelloWorld is our main string. A valid subsequence is Horld -> the order of characters is preserved, but the characters are allowed to be discontinuous.

Input a larger String (b), and then a smaller string (a). Check if the second string(a) exists as a subsequence of the first string (b)
The approach in short: The idea here is very simple. We can check for the longest possible common subsequence between a and b. Since we know the first string is the larger one, the LCS length must correspond to the length of the smaller string (a) for it to be a valid subsequence present in string b.
Thus, we obtain the length of the LCS(a,b), and then in the driver function, we return true if the length of LCS and string a is the same, else return false.

Sample Test Case :
3
DynamicProgramming  DP
HelloWorld  Horld
ABBEGYDH    ABDY
case #1 : 1
case #2 : 1
case #3 : 0
*/

#include "headers.hpp"

int LCS(string &, string &, int, int);
bool sequencePatternMatch(string &a, string &b)
{
    int n = a.size(), m = b.size();
    int lcs = LCS(a, b, n, m);
    return (n == lcs);
}
int LCS(string &a, string &b, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = (1 + dp[i - 1][j - 1]);
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    v(bool) output;
    tests(t)
    {
        string a, b;
        cin >> b >> a;
        output.pb(sequencePatternMatch(a, b));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}