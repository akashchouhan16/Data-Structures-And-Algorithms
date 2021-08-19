#include "headers.hpp"
/* Sample Test Case :
INPUT:
    n = 3, W = 50
    value[] = {60,100,120}
    weight[] = {10,20,30}

OUTPUT : 220
Time Complexity : O(N*W) | Space Complexity : O(N*W) for DP table.
*/

struct item
{
    int *value;
    int *weight;
};

int _01KnapSack(item &it, int n, int W)
{
    int DP[n + 1][W + 1];
    loop(i, n + 1)
    {
        loop(j, W + 1)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else
            {
                if (it.weight[i - 1] <= j)
                {
                    DP[i][j] = max(DP[i - 1][j], it.value[i - 1] + DP[i - 1][j - it.weight[i - 1]]);
                }
                else
                    DP[i][j] = DP[i - 1][j];
            }
        }
    }
    return DP[n][W];
}

int main()
{
    tests(t)
    {
        cout << "ORDER OF I/P : No of items(n) | KnapSack Capacity(W) |n Values | n Weights\n";
        int n, W; //n -> no of items, W-> knapSack capcity.
        cin >> n >> W;
        item it;
        it.value = new int[n];  //values
        it.weight = new int[n]; //weights
        loop(i, n) cin >> it.value[i];
        loop(i, n) cin >> it.weight[i];

        cout << "Maximized Profit : " << _01KnapSack(it, n, W) << endl;
    }
    return 0;
}