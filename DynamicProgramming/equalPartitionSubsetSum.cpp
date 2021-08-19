#include "headers.hpp"

bool canPartition(vi &arr, int n)
{
    ll sum = 0;
    loop(i, n) sum += arr[i];

    if (sum & 1) //if the sum of elements is odd, then it is not possible to partition the vector into equal partitions.
        return false;
    sum /= 2; //now the problem gets reduced to isSubsetSum() for (sum/2)
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[0][i] = false;
    for (int i = 0; i <= sum; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}
int main()
{
    v(bool) output;
    tests(t)
    {
        int n;
        cin >> n;
        vi arr;
        loop(i, n)
        {
            int x;
            cin >> x;
            arr.pb(x);
        }
        output.pb(canPartition(arr, n));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}