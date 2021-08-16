/*Problem Statement : 
We are given an array of size n that contains the coputational times of ith file in arr[i]. We need to perform merge operations between two files in every atomic step. Merge implies adding the computational times of ith and jth files and then pushing it back to the array. WE continue this process till we have merged all the files and are left with only 1 file with the net computattional time. Devise an optimal pattern merge such that the cost (computational time) to merge all the files into 1 is minimum.
i/p : 6                         o/p : Minimum Comp time = 68
     files[] = 2 3 4 5 6 7
*/

#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define pb(x) push_back(x);
#define pp() pop_back()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pqq priority_queue
#define gi greater<int>
#define all(arr) arr.begin(), arr.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define MOD ll(1e9 + 7)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
using namespace std;
inline void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int Solve(vi &files, int n)
{
    files.resize(n);
    pqq<int, vi, gi> minHeap;
    int totalCost = 0;
    for (int i = 0; i < n; i++)
        minHeap.push(files[i]);

    while (minHeap.size() > 1)
    {
        int file1 = minHeap.top();
        minHeap.pop();
        int file2 = minHeap.top();
        minHeap.pop();
        totalCost += (file1 + file2);
        minHeap.push(file1 + file2);
        cout << minHeap.top() << " ";
    }

    return totalCost;
}
int main()
{
    IOS();
    tests(t)
    {
        int n;
        cin >> n;
        vi files;
        loop(i, n)
        {
            int x;
            cin >> x;
            files.pb(x);
        }
        int output = Solve(files, n);
        cout << "Minimum Computations = " << output;
        cout << endl;
    }
}