/*Problem Statement : Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer    modulo 109+7. 
#NOTE nCr = [(n!)/((n-r)!*r!)].
      nCr == nC(n-r).
Sample Test Case :
4
15 3
10 5
3 2 
7 6 
case #1 : 455
case #2 : 252
case #3 : 3  
case #4 : 7 
*/
#include "headers.hpp"
using namespace std;

template <class T>
T nCrCoeffient(T n, T r)
{
    if (n < r)
        return 0;
    r = ((n - r) < r) ? n - r : r;

    T dp[r + 1];
    int modulo = 1000000007;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; //Corresponds to 0C0 = 1
    for (int i = 1; i <= n; i++)
        for (int j = min(r, i); j > 0; --j)
            dp[j] = (dp[j] + dp[j - 1]) % modulo;

    return dp[r];
}
int main()
{
    cout << "Sequence Test Cases, N value, R value :\n";
    vi output;
    tests(t)
    {
        int n, r;
        cin >> n >> r;
        output.push_back(nCrCoeffient(n, r));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}