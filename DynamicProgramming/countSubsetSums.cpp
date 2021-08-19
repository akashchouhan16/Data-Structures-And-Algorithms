#include "headers.hpp"

/*
If the size of the array is 0 and the subset sum is o, it is possible -> 1.
If the size is 0 and sum is >0 then it is never possible -> 0.
If the size if non-zero but the target subset sum is zero, possible-> 1.
Sample test Cases : init dp[][] = { 1 0 0 0 0..
3                                   1 .........
4 6                                 1 .........
1 2 3 3                             1 ......... }
4        
1        
1 1 1 1  
5 10     
4 3 3 6 0
case #1 : 3
case #2 : 4
case #3 : 4
*/
int countSubsetSum(vi &arr, int n, int targetSum)
{

    int dp[n + 1][targetSum + 1];
    for (int i = 0; i <= targetSum; i++)
        dp[0][i] = 0; //first row set to 0.
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1; //first col set to 1.

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= targetSum; j++)
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

    return dp[n][targetSum];
}
int main()
{
    vi output;
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
        output.pb(countSubsetSum(arr, n, targetSum));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}