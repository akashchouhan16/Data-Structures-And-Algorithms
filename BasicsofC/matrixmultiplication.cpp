#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    int arr1[n][n], arr2[n][n], res[n][n];
    memset(res, 0, sizeof res);

    //input part
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)cin >> arr1[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)cin >> arr2[i][j];
    }

    //initialisation
    int i = 0, j = 0, k = 0;

    //solving part
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    //printing
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)cout << res[i][j] << " ";

        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}
