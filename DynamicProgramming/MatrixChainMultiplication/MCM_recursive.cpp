/* Problem Statement : Matrix Chain Multiplication
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same.
Sample Test Case :
3
3
10 20 30      
5
40 20 30 10 30
4
10 30 5 60    
case #1 : 6000
case #2 : 26000
case #3 : 4500
*/
#include "../headers.hpp"

int matrixChainMultiplicationCost(int *arr, int i, int j)
{
    if (i >= j)
        return 0;

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_ans = matrixChainMultiplicationCost(arr, i, k) + matrixChainMultiplicationCost(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (ans > temp_ans)
            ans = temp_ans;
    }
    return ans;
}
int main()
{
    vi output;
    tests(t)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        loop(i, n) cin >> arr[i];
        output.pb(matrixChainMultiplicationCost(arr, 1, n - 1));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}