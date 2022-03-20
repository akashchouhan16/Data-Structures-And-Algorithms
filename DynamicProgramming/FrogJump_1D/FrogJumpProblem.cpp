/* Problem Statement: Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

Sample Test Case:
2
4 10 30 20 10
6 30 10 60 10 60 50
Case #1: 20
Case #2: 40
*/
#include "../headers.hpp"

int Solve(ll index, v(ll) & heights)
{
    if (index == 0)
        return 0;
    ll oneJump = Solve(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    ll twoJumps = INT_MAX;
    if (index > 1)
        twoJumps = Solve(index - 2, heights) + abs(heights[index] - heights[index - 2]);

    return min(oneJump, twoJumps);
}
signed main()
{
    v(int) output;
    tests(t)
    {
        ll n;
        cin >> n;
        v(ll) heights(n);
        loop(i, n)
        {
            ll height;
            cin >> height;
            heights[i] = height;
        }

        output.push_back(Solve(n - 1, heights));
    }

    loop(i, output.size())
    {
        cout << "Case #" << i + 1 << ": " << output[i] << endl;
    }
    return 0;
}