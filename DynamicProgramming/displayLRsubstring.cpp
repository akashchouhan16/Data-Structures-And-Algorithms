/* Problem Statement : Given a string str, Display the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. If there exists more than one such substring return any of them.
[NOTE] : To remove overlapping substring case : dp[i-1][j-1] < (j - i) needs to be fullfilled instead of (i!=j) as seen in case of LRS(S-> subsequence).
Sample Test Case :
4
geeksforgeeks
aab       
banana    
aabaabaaba
case #1 : geeks
case #2 : a    
case #3 : an   
case #4 : aaba
*/
#include "headers.hpp"

string longestRepeatingSubstring(string &str, int n)
{
    string res = "";
    string str2 = str;
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = dp[0][i] = 0;

    int answer = 0, index = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str2[j - 1] and (dp[i - 1][j - 1] < (j - i)))
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (answer < dp[i][j])
                {
                    answer = dp[i][j];
                    index = max(index, i);
                }
            }
            else
                dp[i][j] = 0;
        }
    }
    if (answer <= 0)
        return res; //negative case could either return a null string or a string = "-1".
    for (int i = index - answer; i < index; i++)
        res += str[i];
    return res;
}
int main()
{
    v(string) output;
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