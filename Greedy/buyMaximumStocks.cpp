/*Problem Statement : In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has an amount of k amount of money initially, find out the maximum number of stocks a customer can buy. 
Sample Test Case :
3
3 100  7 10 4
3 45  10 7 19
5 75  10 4 5 2 6

case #1 : 6
case #2 : 4
case #3 : 15
*/
#include "headers.hpp"

int buyMaximumStocks(int *arr, int n, int k)
{
    v(p(int)) data;
    for (int i = 0; i < n; i++)
        data.push_back(make_pair(arr[i], i + 1));

    std::sort(data.begin(), data.end()); //sorted based on price -> min to max price
    int stockCount = 0;

    for (int i = 0; i < n; i++)
    {
        int stock = data[i].second;
        int price = data[i].first;
        if (price * stock <= k)
        {
            stockCount += stock;
            k -= price * stock;
        }
        else
        {
            stockCount += (k / price);
            k -= price * (k / price);
        }
    }
    return stockCount;
}
int main()
{
    vi output;
    tests(t)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        loop(i, n) cin >> arr[i];

        output.pb(buyMaximumStocks(arr, n, k));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}