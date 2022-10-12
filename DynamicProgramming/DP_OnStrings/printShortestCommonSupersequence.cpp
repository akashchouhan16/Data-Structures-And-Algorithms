#include "headers.hpp"
/* Problem Statement : A follow up problem of the Shortest Common Supersequence Problem.
We can output any p&c of the resultant string. For example, a = "geek", b = "eke" -> the shortest possible supersequence will be of length = 5. Any valid string with both a & b strings as subsequences and of SCS length is allowed. (eg: "geeke", "gekek", etc.)

Sample Test Case :
3
geek eke
racecar aceit
students tents
case #1 : gekek    
case #2 : raceitcar
case #3 : students
*/
int **LCS(string s1, string s2, int n, int m)
{
    int **dp = new int *[n + 1];
    loop(i, n + 1)
        dp[i] = new int[m + 1];

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
    return dp;
}
string printShortestCommonSuperSequence(string s1, string s2, int n, int m)
{
    int **dp = LCS(s1, s2, n, m);
    string output = "";
    int i = n, j = m;

    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            output += (s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                output += (s2[j - 1]);
                j--;
            }
            else
            {
                output += (s1[i - 1]);
                i--;
            }
        }
    }
    while (i > 0)
    {
        output += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        output += s2[j - 1];
        j--;
    }
    reverse(output.begin(), output.end()); //not needed here, as the length and the count of the resultant characters are preserved.
    return output;
}

int main()
{
    v(string) output;
    tests(t)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        output.pb(printShortestCommonSuperSequence(s1, s2, n, m));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}