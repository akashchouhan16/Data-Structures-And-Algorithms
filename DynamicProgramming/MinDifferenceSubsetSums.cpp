/* Problem Statement : (Tricky KnapSack_SubsetSub based variation)
We are provided with an array of N elements. We need to partition the array into two subsets p1 and p2 with their sums
equal to S1(smaller subsetSum) and S2, just that we have the minimum possible difference between the subset sums
i.e. |S2-S1| is minimized.

Approach In Short : WE do not need to compute S2 subset sum if we have the sum of N elements(Range) and the subset sum S1.
If one Subset sums up to S1, then the other subset will be (Range - S1). Hence, we have reduced the problem to a single variable -> we need to minimized |S2-S1| => |(Range-S1) - S1| => |Range - 2*S1|

{Note : The max possible sum from a subset will the sum of all the array elements, and the min possible subset sum will always be 0 in case of empty set {}.}
* We utilize the isSubsetSum() problem to output us with all the permissible sum values that the subset S1 can have,
and then we simply need to output the min of all the (Range - 2*S1) from the driver method. 
Sample Test Case : 
2
4 6 1 5 11
3 7 1 2
OUTPUT :
case #1 : 1
case #2 : 4
*/
#include "headers.hpp"

vector<bool> isSubsetSum(vi &arr, int Range, int n)
{
    bool dp[n + 1][Range + 1];
    // init dp
    for (int i = 0; i <= Range; ++i)
        dp[0][i] = false;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;
    vector<bool> allowedValues((Range + 1) / 2, false);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= Range; j++)
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
    // Copy the last row of permissible subsetSum values :
    for (int i = 0; i <= (Range + 1) / 2; i++)
    {
        allowedValues[i] = dp[n][i];
    }
    return allowedValues;
}
int minDifferenceSubsetSum(vi &arr, int n, int Range)
{
    int ans = INT_MAX;
    v(bool) allowedValues = isSubsetSum(arr, Range, n);

    loop(i, allowedValues.size())
    {
        if (allowedValues[i])
            ans = min(ans, (Range - 2 * i));
    }
    return ans;
}
int main()
{
    vi output;
    tests(t)
    {
        int n, Range = 0;
        cin >> n;
        vi arr;
        loop(i, n)
        {
            int x;
            cin >> x;
            Range += x;
            arr.pb(x);
        }
        output.pb(minDifferenceSubsetSum(arr, n, Range));
    }
    cout << "OUTPUT : \n";
    int x = 1;
    loop(i, output.size()) cout << "case #" << x++ << " : " << output[i] << endl;
    return 0;
}