/*Problem Statement : Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text. The matching should cover the entire text (not partial text).
The wildcard pattern can include the characters ‘?’ and ‘*’ 
‘?’ – matches any single character 
‘*’ – Matches any sequence of characters (including the empty sequence)

Sample Test Case
3
baaa?ab baaabab
b*ba baaaabab  
ba*a? babab
case #1 : YES
case #2 : NO
case #3 : YES
*/

#include "headers.hpp"
using namespace std;

int dp[1001][1001];

int isPatternMatching(string &pattern, string &strData, int i, int j)
{
    if (i == -1 and j == -1)
        return 1; //both the strings have terminated together => Definitely a Match.
    if (i == -1)
        return 0; //Since pattern has terminated, but string data hasn't => Definitely not a Match.
    if (j == -1)
    {
        //if the string data has terminated, but the pattern hasn't, then there is a possibility of a Match if all the remaining characters in the pattern are '*'.
        for (int x = 0; x < i; x++)
            if (pattern[x] != '*')
                return 0;
        return 1;
    }
    // Memoization value :
    if (dp[i][j] != -1)
        return dp[i][j];

    if (pattern[i] == strData[j] or pattern[i] == '?')
        return dp[i][j] = isPatternMatching(pattern, strData, i - 1, j - 1);
    if (pattern[i] == '*')
    {
        // option 1 : To consume the character of strData into out * of the pattern string.
        int option_1 = isPatternMatching(pattern, strData, i, j - 1);
        // Option 2 : To consider the '*' as a null character or 0 and move to next char in our pattern string.
        int option_2 = isPatternMatching(pattern, strData, i - 1, j);
        return dp[i][j] = (option_1 or option_2);
    }
    return dp[i][j] = 0;
}
int main()
{
    v(string) output;
    memset(dp, -1, sizeof(dp));
    tests(t)
    {
        string pattern, strData;
        cin >> pattern >> strData;
        int m = pattern.size(), n = strData.size();
        output.pb(isPatternMatching(pattern, strData, m - 1, n - 1) ? "YES" : "NO");
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}