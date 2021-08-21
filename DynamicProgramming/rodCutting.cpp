/* Problem Statement : 
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 
Example: 
If length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

Sample Test Case : 
2
8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20
3
1 2 3
20 30 10
case #1 : 22
case #2 : 60

*/
#include "headers.hpp"

int rodCutting(vi &lengths, vi &prices, int N)
{
    int n = lengths.size();
    int dp[n + 1][N + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (lengths[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], prices[i - 1] + dp[i][j - lengths[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][N];
}
int main()
{
    vi output;
    tests(t)
    {
        int N;
        cin >> N; //N corresponds to knapSack capacity (W) in the classical problem. **for refrence.
        vi lengths(N), prices(N);
        loop(i, N) cin >> lengths[i];
        loop(i, N) cin >> prices[i];

        output.pb(rodCutting(lengths, prices, N));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}