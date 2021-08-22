#include "../headers.hpp"
/*
Sample Test Case : 
2
Enter Two Strings : hegstu  hgxsttu
Enter Two Strings : abedfhr abcdgh
OUTPUT using Bottom Up Approach : 
case #1 : 5
case #2 : 4
OUTPUT using Top Down Approach :  
case #1 : 5
case #2 : 4
*/
int LCS_memoized(string str1, string str2, int n, int m, int **dp)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (str1[n - 1] == str2[m - 1])
        return dp[n][m] = (1 + LCS_memoized(str1, str2, n - 1, m - 1, dp));
    else
        return dp[n][m] = max(LCS_memoized(str1, str2, n - 1, m, dp), LCS_memoized(str1, str2, n, m - 1, dp));
}

int LCS_topDown(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    // Init the dp for base case -> n==0 || m==0 must return 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
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
    vi output1, output2;
    // Output1 stores solns for the Bottom Up approach.
    // Output2 stores solns for the Top Down approach.
    tests(t)
    {
        string str1, str2;
        cout << "Enter Two Strings : ";
        cin >> str1 >> str2;
        int n = str1.size(), m = str2.size();

        int **dp = new int *[n + 1];
        loop(i, n + 1) dp[i] = new int[m + 1];

        loop(i, n + 1)
            loop(j, m + 1)
                dp[i][j] = -1;

        output1.pb(LCS_memoized(str1, str2, n, m, dp));
        output2.pb(LCS_topDown(str1, str2, n, m));
    }
    cout << "OUTPUT using Bottom Up Approach : \n";
    loop(i, output1.size()) cout << "case #" << i + 1 << " : " << output1[i] << endl;
    cout << "OUTPUT using Top Down Approach : \n";
    loop(i, output2.size()) cout << "case #" << i + 1 << " : " << output2[i] << endl;
    return 0;
}