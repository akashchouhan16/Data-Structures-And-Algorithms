/* Problem Statement : 
Sample Test Cases : 
2
4 4
1 3 1 5
2 2 4 1
5 0 2 3
0 6 1 2
3 3
1 3 3
2 1 4
0 6 4
case #1 : 16
case #2 : 12
*/

#include "headers.hpp"
using namespace std;
// Utils :
void input(int **mineYard, int &m, int &n)
{
    loop(i, m)
    {
        loop(j, n)
        {
            cin >> mineYard[i][j];
        }
    }
    return;
}

void display(int **mineYard, int &m, int &n)
{
    loop(i, m)
    {
        loop(j, n)
        {
            cout << mineYard[i][j] << ".";
        }
        cout << endl;
    }
    return;
}
int maximumGoldExtracted(int **mineYard, int &m, int &n)
{
    if (m <= 0 || n < 0) //invalid inputs
        return -1;
    for (int j = n - 2; j >= 0; j--)
    {
        for (int i = 0; i < m; i++)
        {
            int right = mineYard[i][j + 1];
            int rightUp = (i == 0) ? 0 : mineYard[i - 1][j + 1];
            int rightDown = (i == m - 1) ? 0 : mineYard[i + 1][j + 1];

            mineYard[i][j] = mineYard[i][j] + max(right, max(rightUp, rightDown));
        }
    }
    int maxGoldUnits = mineYard[0][0];
    for (int i = 0; i < m; i++)
        maxGoldUnits = (maxGoldUnits < mineYard[i][0]) ? mineYard[i][0] : maxGoldUnits;
    return maxGoldUnits;
}
int main()
{
    vi output;
    tests(t)
    {
        int m, n;
        cin >> m >> n;
        int **mineYard = new int *[m];
        loop(i, m)
            mineYard[i] = new int[n];
        // memset(mineYard, -1, sizeof(mineYard));
        input(mineYard, m, n);

        // cout << "Mine Yard : \n";
        // display(mineYard, m, n);
        output.pb(maximumGoldExtracted(mineYard, m, n));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}