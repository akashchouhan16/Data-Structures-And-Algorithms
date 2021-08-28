/*Problem Statement : In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
Sample Test Case :
3
4 2
3 2 1 4
5 4
3 2 1 4 5
7 3
4 8 7 3 5 2 1
case #1 :  Min->3 Max->7
case #2 :  Min->1 Max->5
case #3 :  Min->3 Max->15 
*/
#include "headers.hpp"
int getMin(int *, int, int);
int getMax(int *, int, int);

p(int) minMaxCostToBuyNCandies(int *candies, int n, int k)
{
    int minCost = getMin(candies, n, k);
    int maxCost = getMax(candies, n, k);
    return make_pair(minCost, maxCost);
}
int getMin(int *arr, int n, int k)
{
    int cost = 0;
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while (i <= j)
    {
        cost += arr[i];
        // pick k candies from the end for free.
        j -= k;
        i++;
    }
    return cost;
}
int getMax(int *arr, int n, int k)
{
    int cost = 0;
    sort(arr, arr + n, greater<int>());
    int i = 0, j = n - 1;
    while (i <= j)
    {
        cost += arr[i];
        // pick k candies from the end for free.
        j -= k;
        i++;
    }
    return cost;
}
int main()
{
    vector<p(int)> output;
    tests(t)
    {
        int n, k;
        cin >> n >> k;
        int *candies = new int[n];
        loop(i, n) cin >> candies[i];

        output.pb(minMaxCostToBuyNCandies(candies, n, k));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " :  Min->" << output[i].first << " Max->"
                                << output[i].second << endl;
    return 0;
}