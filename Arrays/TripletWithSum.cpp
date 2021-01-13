#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
// Time Complexity of This Solution is O(nlogn).
class tripletSum
{
    int *arr;
    int n;

public:
    tripletSum()
    {
        cout << "Enter size : ";
        cin >> n;
        arr = new int[n];
        randomInput();
    }
    void randomInput()
    {
        int n1, n2;
        cout << "Enter Range : ";
        cin >> n1 >> n2;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = n1 + rand() % (n2 - n1 + 1);
        }
        sort(arr, arr + n);
        return;
    }
    void Display()
    {
        for (int i = 0; i < n; i++)
            cout << *(arr + i) << " ";
        cout << endl;
    }
    bool getTriplet()
    {
        int sum;
        cout << "Enter Sum : ";
        cin >> sum;
        int i, l, r;
        for (int i = 0; i < n - 2; i++)
        {
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                if (arr[i] + arr[l] + arr[r] == sum)
                {
                    cout << "Required Triplet : " << arr[i] << "," << arr[l] << "," << arr[r] << endl;
                    return true;
                }
                else if (arr[i] + arr[l] + arr[r] > sum)
                    r--;
                else if (arr[i] + arr[l] + arr[r] < sum)
                    l++;
            }
        }
        return false;
    }
    ~tripletSum()
    {
        delete[] arr;
        cout << "Code terminated!\n";
    }
};

int main()
{
    tripletSum obj;
    cout << "Input Array : ";
    obj.Display();
    bool check = obj.getTriplet();
    if (!check)
        cout << "Triplet with required sum doesnt exist.\n";
    return 0;
}
