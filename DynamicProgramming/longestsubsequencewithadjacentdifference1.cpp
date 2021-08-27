/* Problem Statement :
Given an array of n size, the task is to find the longest subsequence such that difference between adjacents is one. 
Sample Test Case :
3
5
1 2 3 4 5
7
10 9 4 5 4 8 6
3
4 6 7
case #1 : 5
case #2 : 3
case #3 : 2 
*/

#include "headers.hpp"

int longestSSWithAdjacentDiffOne(int *arr, int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = 1;
    int ans = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] == (arr[j] - 1) || arr[i] == (arr[j] + 1))
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = 0; i <= n; i++)
        if (ans < dp[i])
            ans = dp[i];
    return ans;
}
int main()
{
    vi output;
    tests(t)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        loop(i, n) cin >> arr[i];

        output.pb(longestSSWithAdjacentDiffOne(arr, n));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}