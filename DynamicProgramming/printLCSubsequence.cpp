#include "headers.hpp"

/*
Sample Test Case : 
2
abdegfr
adgtfrw
hgxsttu
hegstu
case #1 : adgfr
case #2 : hgstu
*/
int **LCS(string s1, string s2, int n, int m)
{
    int **dp = new int *[n + 1];
    loop(i, n + 1)
        dp[i] = new int[m + 1];
    // init for base case -> If either of the string is null, common subsequence length will be 0.
    for (int i = 0; i <= m; ++i)
        dp[0][i] = 0;
    for (int i = 0; i <= n; ++i)
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
    return dp;
}
string lcsStrings(string s1, string s2, int n, int m)
{
    string res = "";
    int **dp = LCS(s1, s2, n, m);
    int i = n, j = m;

    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    // resultant string has to be reversed in order to get the required LCS.
    int low = 0, high = res.size() - 1;
    while (low <= high)
    {
        swap(res[low], res[high]);
        low++;
        high--;
    }
    return res;
}
int main()
{
    v(string) output;
    tests(t)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();

        output.pb(lcsStrings(s1, s2, n, m));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
}