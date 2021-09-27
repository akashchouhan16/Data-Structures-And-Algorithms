/* Problem Statement : Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
Sample Test Case : 
4
4 2
12 34 67 90   
5 3
10 20 30 40 50
7 3
15 45 25 35 60 50 10
3 2
10 15 20
case #1 : 113
case #2 : 60
case #3 : 95
case #4 : 25
*/
#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define pb(x) push_back(x)
#define pp() pop_back();
#define all(x) x.begin(), x.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(a, b) for (int i = a; i <= b; i++)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)

using namespace std;

void input(int *data, int &n)
{
    loop(i, n) cin >> data[i];
}
void display(int *data, int &n)
{
    loop(i, n) cout << data[i] << " ";

    cout << endl;
    return;
}
int maxElement(int *books, int &N)
{
    int max = INT_MIN;
    loop(i, N)
    {
        max = (max < books[i]) ? books[i] : max;
    }
    return max;
}

int sumOfElements(int *books, int &N)
{
    int sum = 0;
    loop(i, N) sum += books[i];
    return sum;
}

bool isValid(int *books, int &N, int &K, int maxAllowed)
{
    int studentCount = 1, sumOfPages = 0;
    loop(i, N)
    {
        sumOfPages += books[i];
        if (sumOfPages > maxAllowed)
        {
            studentCount++;
            sumOfPages = books[i];
        }
        if (studentCount > K) //if required studentCount becomes greater than available students K, return not valid.
            return false;
    }
    return true;
}
int allocateMinPages(int *books, int &N, int &K)
{
    if (N < K)
        return -1;

    int res = -1;
    int low = maxElement(books, N);
    int high = sumOfElements(books, N);
    // cout << low << " to " << high << endl;                 /*[To Test Range]*/
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(books, N, K, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
signed main()
{
    v(int) output;
    tests(t)
    {
        int N, K; //N is the number of books, K is the number of available students.
        cin >> N >> K;
        int *books = new int[N];
        input(books, N);
        output.pb(allocateMinPages(books, N, K));
    }

    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;

    return 0;
}