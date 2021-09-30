/*Problem Statement : Given three stacks of the positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. Stacks are represented as an array, and the first index of the array represent the top element of the stack. 
Link : geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/

Sample Test Cases : 
3
3 4 2
1 5 6
3 6 2 1
7 4
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1
2 2 2
3 10
4 5
2 1
case #1 : 0
case #2 : 5
case #3 : 0
*/
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define MOD ll(1e9 + 7)
#define vi vector<int>
#define v(x) vector<x>
#define p(x) pair<x, x>
#define pb(x) push_back(x)
#define pp() pop_back()
#define all(arr) arr.begin(), arr.end();
#define loop(i, n) for (int i = 0; i < n; i++)
#define xloop(a, b) for (int j = a; j <= b; j++)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)

using namespace std;
int Solve(int *st1, int *st2, int *st3, int n1, int n2, int n3, int sum1, int sum2, int sum3)
{
    int ans = 0;
    int top1 = 0, top2 = 0, top3 = 0;
    while (true)
    {
        if (top1 == n1 or top2 == n2 or top3 == n3)
        {
            ans = 0;
            break;
        }
        if (sum1 == sum2 and sum2 == sum3)
        {
            ans = sum1;
            break;
        }
        if (sum1 >= sum2 and sum1 >= sum3)
            sum1 -= st1[top1++];
        else if (sum2 >= sum1 and sum2 >= sum3)
            sum2 -= st2[top2++];
        else if (sum3 >= sum1 and sum3 >= sum2)
            sum3 -= st3[top3++];
    }
    return ans;
}
signed main()
{
    vi output;
    tests(t)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int st1[n1], st2[n2], st3[n3];
        int sum1 = 0, sum2 = 0, sum3 = 0;
        // input stack data for 3 stacks
        loop(i, n1)
        {
            cin >> st1[i];
            sum1 += st1[i];
        }
        loop(i, n2)
        {
            cin >> st2[i];
            sum2 += st2[i];
        }
        loop(i, n3)
        {
            cin >> st3[i];
            sum3 += st3[i];
        }

        output.pb(Solve(st1, st2, st3, n1, n2, n3, sum1, sum2, sum3));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}