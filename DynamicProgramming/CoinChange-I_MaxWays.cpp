/*Problem Statement : You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
[LC-518]
Sample Test Case :
2
1 3
2
3 5
1 2 5
case #1 : 0
case #2 : 4
*/
#include "headers.hpp"

int maxNumberOfWaysToAmt(vi &coins, int n, int amount)
{
    int dp[n + 1][amount + 1];

    //if 0 coins are provided, no amount can be achieved expect for amt=0
    for (int i = 0; i <= amount; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j]) + (dp[i][j - coins[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][amount];
}
int main()
{
    vi output;
    tests(t)
    {
        int n, amount;
        cin >> n >> amount;
        vi coins(n);
        loop(i, n) cin >> coins[i];

        output.pb(maxNumberOfWaysToAmt(coins, n, amount));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}