#include "headers.hpp"
/* Problem Statement : Given an array of n elements, and a target Sum (SUM). Check if their exists a subset with the given sum SUM. Return true if it does, else return false.

Sample test Case :
INPUT :
n= 6 targetSum = 9
arr[] = {3,34,4,12,5,2}
n = 6 targetSum = 30
arr[] = {3,34,4,12,5,2}
---------------------------------------------------------
BRUTE Force : O(N^2) -> Using nested loop, to obtain the sum of all possible subsets and then comparing with the target sum. If found, we return true, else return false.

*/

bool subSetSum(vi &arr, int target)
{
    int n = arr.size();
    int dp[n + 1][target];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= target; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {

            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
}
int main()
{
    tests(t)
    {
        int n, targetSum;
        cin >> n >> targetSum;
        vi arr;
        loop(i, n)
        {
            int x;
            cin >> x;
            arr.pb(x);
        }
        cout << subSetSum(arr, targetSum) << endl;
    }

    return 0;
}