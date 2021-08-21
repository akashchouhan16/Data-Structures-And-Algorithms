#include "headers.hpp"

/* Sample Test cases : 
2   
4 1
2 3 4 5
3 6
3 7 10
case #1 : 2
case #2 : 1
*/
int isSubsetSum(vi &arr, int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int countNoOfSubsets(vi &arr, int n, int difference)
{
    int sum = 0;
    loop(i, n) sum += arr[i];
    /* 
        s1 = (sum + difference)/2; we perform the subsetSum count on S1, to obtain the desired output.
    */
    int requiredSum = (sum + difference) >> 1;
    return isSubsetSum(arr, n, requiredSum);
}
int main()
{
    vi output;
    tests(t)
    {
        int n, difference;
        cin >> n >> difference;
        vi arr;
        loop(i, n)
        {
            int x;
            cin >> x;
            arr.pb(x);
        }
        output.pb(countNoOfSubsets(arr, n, difference));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
}