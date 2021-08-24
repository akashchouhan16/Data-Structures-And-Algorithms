/*  Problem Statement: Minimum number of deletions to make a string palindrome
Given a string of size ‘n’. The task is to remove or delete a minimum number of characters from the string so that the resultant string is a palindrome.

Sample Test Case :
3
aebcbda
geeksforgeeks
racecar
case #1 : 2
case #2 : 8
case #3 : 0 
*/

#include "headers.hpp"
int LCS(string, string, int);
int minDeletionsToMakeStringPalindrome(string str, int n)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return n - LCS(str, revStr, n);
}

int LCS(string a, string b, int n)
{
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = (1 + dp[i - 1][j - 1]);
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
        string str;
        cin >> str;
        int n = str.size();
        output.pb(minDeletionsToMakeStringPalindrome(str, n));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}