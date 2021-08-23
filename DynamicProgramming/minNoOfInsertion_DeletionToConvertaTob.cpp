/* Problem Statement : Minimum Number Of Insertions & Deletions needed in order to convert string a to string b.

Approach in short : The idea here is to identify the longest common subsequnce in a and b -> lcs.
We can now utilize the lcs to obtain the differnces between the lengths of string a and that of string b , and the sum total of the differences is the resultant number of changes required in order to convert our string from a to b.

To compute the deletions needed : lengthOfstring(a) - lcs )-> res1
To compute the insertions needed : lengthOfString(b) - lcs )-> res2
Resultant difference = res1 + res2 ->  The required answer.

Essentially, we are converting the string through the lcs. We count the number of operations(deletions) needed to get to lcs, and then we count the number of operations(insertions) need to get to string b from lcs, and add them both. 

Sample Test Case :
3
heap pea
geeksforgeeks forgeeks
schoolstudents students
case #1 : 3
case #2 : 5
case #3 : 6
*/
#include "headers.hpp"

int LCS(string &, string &, int, int);
int minInsertionDeletionToConvertString(string a, string b, int n, int m)
{
    int lcs = LCS(a, b, n, m);
    return (n - lcs) + (m - lcs); //(No of Deletions) + (No of Insertions)
}
int LCS(string &a, string &b, int n, int m)
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
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
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
    vi output;
    tests(t)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        output.pb(minInsertionDeletionToConvertString(s1, s2, n, m));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
}