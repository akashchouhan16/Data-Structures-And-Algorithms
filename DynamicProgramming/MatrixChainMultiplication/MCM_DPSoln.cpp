/*
Optimised Solution of Matrix Chain Multiplication Problem using the Bottom Up Dynamic Programming.
Sample Test Case :
3
3
10 20 30      
5
40 20 30 10 30
4
10 30 5 60    
case #1 : 6000
case #2 : 26000
case #3 : 4500
*/
#include "../headers.hpp"

int matrixChainMultiplicationCost(int *arr, int i, int j, int *dp[])
{
    if (i >= j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_ans = matrixChainMultiplicationCost(arr, i, k, dp) + matrixChainMultiplicationCost(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);
        if (ans > temp_ans)
            ans = temp_ans;
    }
    return dp[i][j] = ans;
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
        int **dp = new int *[n + 1];
        loop(i, n + 1)
        {
            dp[i] = new int[n + 1];
        }
        // memset(dp, -1, sizeof(dp)); did not work on system compiler, hence manually assigned -1 to dp[][].
        loop(i, n + 1)
        {
            loop(j, n + 1)
                dp[i][j] = -1;
        }
        output.pb(matrixChainMultiplicationCost(arr, 1, n - 1, dp));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}