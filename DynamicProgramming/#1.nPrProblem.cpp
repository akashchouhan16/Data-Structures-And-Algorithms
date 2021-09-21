/* Problem Statement : Given two numbers n and r, the task is to find the value of nPr. 
nPr represents n permutation r which is calculated as n!/(n-k)!. Permutation refers to the process of arranging all the members of a given set to form a sequence.
Sample Test Cases : 
3
15 7
17 5
20 14
case #1 : 32432400        
case #2 : 742560
case #3 : 3379030566912000
*/
#include "headers.hpp"
using namespace std;

// Approach I : Linear Time O(N) and Linear Space O(N).
template <class T>
T permutationCoeffient(T n, T k)
{
    if (n < 0 || k > n)
        return 0; //invalid inputs
    T dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        dp[i] = dp[i - 1] * i;
    // nPr = n!/(n-k)!
    return dp[n] / (dp[n - k]);
}

// Approach II (Optimised) : linear Time O(N) and Constant Space O(1).
/* Calculation : nPr = (n!)/(n-r)!
                     = {(n*(n-1)((n-2)*(n-3)...(n-r+1)*(n-r)!)/(n-r)!}
                     = (n*(n-1)*(n-2)...(n-r+1)) ANS
*/
template <class T>
T optimised_nPr(T n, T k)
{
    if (n < 0 || k > n)
        return 0; //invalid inputs
    T ans = 1;
    for (int i = 0; i < k; ++i)
        ans *= (n - i);
    return ans;
}
int main()
{
    v(ll) output, output2;
    cout << "Sequence : test Cases, N value, K value\n";
    tests(t)
    {
        ll n, k;
        cin >> n >> k;
        output.push_back(permutationCoeffient(n, k));
        output2.push_back(optimised_nPr(n, k));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    loop(i, output2.size()) cout << "case #" << i + 1 << " : " << output2[i] << endl;
    return 0;
}