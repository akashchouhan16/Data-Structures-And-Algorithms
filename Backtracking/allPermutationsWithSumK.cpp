/* Problem Statement: Given an array of N element and an integer K, Print all the subsequence that sum up to K.

Solution:
Enter No. of Tests: 2
Enter N and K: 3 2
1 2 1
1 1
2
Enter N and K: 5 4
1 3 2 0 4
1 3 0
1 3
0 4
4
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define INF2 INT_MIN
#define ll long long

using namespace std;

class Solution
{
    vector<int> data;
    vector<vector<int>> result;
    int K, N;

    void Solve(int index, int &currentSum, vector<int> &temp)
    {
        if (currentSum > K)
            return; // not possible with the current subsequence and hence return back to prev call.
        if (index == N)
        {
            if (currentSum == K)
                result.push_back(temp);
            return;
        }

        // Pick the element.
        temp.push_back(data[index]);
        currentSum += data[index];
        Solve(index + 1, currentSum, temp);

        // Not pick the element.
        temp.pop_back();
        currentSum -= data[index];
        Solve(index + 1, currentSum, temp);
    }

public:
    Solution() {}
    Solution(int n, int k = 0) : N(n), K(k) { data = vector<int>(N, 0); }
    void input()
    {
        for (int i = 0; i < N; i++)
            cin >> data[i];
    }

    void generateAllPermutationSumK();
    void displayResult();
};

void Solution::generateAllPermutationSumK()
{
    vector<int> temp; // store temporary permutations with sum = currentSum.
    int currentSum = 0;
    Solve(0, currentSum, temp);
    return;
}

void Solution::displayResult()
{
    for (auto &row : result)
    {
        for (int i = 0; i < row.size(); i++)
            cout << row[i] << " ";
        cout << endl;
    }
    return;
}

int main()
{
    int t;
    cout << "Enter No. of Tests: ";
    cin >> t;
    while (t--)
    {
        cout << "Enter N and K: ";
        int n, k;
        cin >> n >> k;
        Solution obj(n, k);
        obj.input();

        obj.generateAllPermutationSumK();
        obj.displayResult();
    }
    return 0;
}