// Ternary Search Implementation :
/* Time Complexity : O(log base3 N) 
At every step : The container is divided into 3 parts (1/3) with two mid points.
Since every step 2/3 of the elements are eliminated, it seems to perform faster than binary sarch, however, the number of comparisions in ternary is twice compared to binary search and this significantly inc the overall Time Complexity of the Ternary Search algorithm. Hence, Bin Search is often preferred over Ternary.
*/
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
using namespace std;
void input(vector<int> &arr, int n)
{
    int r1, r2;
    cout << "Enter the range : ";
    cin >> r1 >> r2;
    srand(time(nullptr));
    loop(i, n)
        arr.pb(r1 + rand() % (r2 - r1 + 1));
    sort(all(arr));
    return;
}
void Display(vector<int> &arr, int n)
{
    loop(i, n)
        printf("%d ", arr[i]);
    cout << endl;
    return;
}
// Algo :
int TernarySearch(vector<int> &arr, int key)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    int l = 0, h = n - 1;
    int midFirst = l + (h - l) / 3;
    int midSecond = midFirst + (h - l) / 3;

    while (l <= h)
    {
        midFirst = l + (h - l) / 3;
        midSecond = midFirst + (h - l) / 3;
        if (arr[midFirst] == key)
            return midFirst;
        else if (arr[midSecond] == key)
            return midSecond;

        else if (key > arr[midFirst])
            l = midFirst + 1;
        else if (key < arr[midSecond])
            h = midSecond - 1;
        else
        {
            l = midFirst + 1;
            h = midSecond - 1;
        }
    }
    return -1;
}
int main()
{
    cout << "Enter the # of tests : ";
    test(t)
    {
        int n, key;
        cin >> n;
        vector<int> arr;
        input(arr, n);
        cout << "Input : ";
        Display(arr, n);
        cout << "Enter the key to search : ";
        cin >> key;
        int res = TernarySearch(arr, key);
        if (res == -1)
            cout << "Element not Found!\n";
        else
            cout << "Element Found at idx : " << res << endl;

        arr.erase(all(arr));
    }
    return 0;
}
