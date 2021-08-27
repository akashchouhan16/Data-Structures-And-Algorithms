/* Problem Statement : Given a string str, find the length of longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. If there exists more than one such substring return any of them.
[NOTE] : To remove overlapping substring case : dp[i-1][j-1] < (j - i) needs to be fullfilled instead of (i!=j) as seen in case of LRS(S-> subsequence).

Sample Test Case :
3
aab       
banana    
aabaabaaba
case #1 : 1
case #2 : 2
case #3 : 4
*/
#include "headers.hpp"

int longestRepeatingSubstring(string &str, int n)
{
    int dp[n + 1][n + 1];
    string str2 = str;

    for (int i = 0; i <= n; i++)
        dp[i][0] = dp[0][i] = 0;
    int answer = INT_MIN + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str2[j - 1] and (dp[i - 1][j - 1] < (j - i)))
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                answer = max(dp[i][j], answer);
            }
            else
                dp[i][j] = 0;
        }
    }
    return answer;
}
int main()
{
    vi output;
    tests(t)
    {
        string str;
        cin >> str;
        int n = str.size();

        output.pb(longestRepeatingSubstring(str, n));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}