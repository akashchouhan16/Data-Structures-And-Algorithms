/* Standard Leetcode Problem on subSetSum vairation. 
We are provided with an array of N elements. We can assign either -ve or +ve sign to the element.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Approach in Short : 
we know if we part the array into two subsets P1 and P2 with subset sum as S1 and S2 respectively,
S1 + S2 = SumOfElements(arr,n);  -> (i)
S1 - S2 = targetSum              -> (ii)
S1 = (sum + targetSum)/2 Soln is reduced to this expression by adding equation (i) & (ii)
We can now utilize the isSubsetSum() to compute the count of subsets that give a sum S1.
[similar approach to count subsets with given difference]
Sample Test Case :
2
5 3
1 1 1 1 1
1 1
1
case #1 : 5
case #2 : 1
*/
#include "headers.hpp"

int targetSum(vi &arr, int n, int target)
{
    int sum = 0;
    loop(i, n) sum += arr[i];
    //Edge cases :
    if ((target + sum) & 1 || target < -sum || target > sum)
        return 0;

    int reqSum = (target + sum) / 2;
    int dp[n + 1][reqSum + 1];

    for (int i = 0; i <= reqSum; ++i)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= reqSum; j++)
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
    return dp[n][reqSum];
}
int main()
{

    vi output;
    tests(t)
    {
        int n, target;
        cin >> n >> target;
        vi arr;
        loop(i, n)
        {
            int x;
            cin >> x;
            arr.pb(x);
        }
        output.pb(targetSum(arr, n, target));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}