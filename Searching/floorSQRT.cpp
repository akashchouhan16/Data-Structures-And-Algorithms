#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#define MAX 1e5 + 2
#define nullptr NULL
#define loop(i, n) for (int i = 0; i < n; i++)
#define pb(x) push_back(x)
#define all(a) a.begin(), a.end()
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)
#define intx long long
using namespace std;

//To fnd the fllor of sqrt of an input int
int floorSQRT(intx num)
{
    if (num < 0)
        return -1; //invalid
    int l = 1, h = num >> 1;
    intx mid = 1, ans = mid;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (mid * mid == num)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < num)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return ans;
}
int main()
{
    cout << "Enetr # of tests :";
    test(t)
    {
        intx num;
        cin >> num;
        cout << "SQRT(" << num << ") = " << floorSQRT(num) << endl;
    }
    return 0;
}