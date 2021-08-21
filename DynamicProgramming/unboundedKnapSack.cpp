/* Problem Statement : In the classical knapSack problem, we can either select and item Xi, which will add profit VALi and will reduce the knapsack capacity by Weight[i], or we can skip the item. In both the cases, we mark the item as processed and we never consider that item again for processing.

UnBounded KnapSack is a slight variation of the same problem. The only difference here is that, if we choose not to select an item, we mark it as processsed and move to next item in the list. However, if we select the item, we add the valu to our profit, our knapsack capacity is also reduced by weight[i], but we do not mark the selected item as processed, thus allowing multiple instances of a particular item into out knapsack to maximize our profit.
Therefore,  arr[i]->(we have a choice)
                       /           \
                    Do not         Select item
                    select          (Do not flag
                  (flag it as        it as processed)
                   processed)
Sample Test Cases :
2
4 8        
10 40 50 70
1 3 4 5    
2 100
1 30
1 50
case #1 : 110
case #2 : 100 
*/
#include "headers.hpp"

struct items
{
    int *values;
    int *weights;
};

int unboundedKnapSack(items &it, int n, int W)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (it.weights[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], it.values[i - 1] + dp[i][j - it.weights[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][W];
}

int main()
{
    vi output;
    tests(t)
    {
        int n, W; //n is the no of items, W is the knapSack capacity.
        cin >> n >> W;
        items it;
        it.values = new int[n];
        it.weights = new int[n];
        loop(i, n) cin >> it.values[i];
        loop(i, n) cin >> it.weights[i];

        output.pb(unboundedKnapSack(it, n, W));
        delete[] it.values;
        delete[] it.weights;
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}