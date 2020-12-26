#include <bits/stdc++.h>
using namespace std;
class LastOccurrence
{
    int n;
    int *arr;

public:
    LastOccurrence(int s = 5) : n(s)
    {
        arr = new int[n];
        randomInput();
    }
    void randomInput()
    {
        int n1, n2;
        cout << "Enter Element range : ";
        cin >> n1 >> n2;
        for (int i = 0; i < n; i++)
            arr[i] = n1 + rand() % (n2 - n1 + 1);
        std::sort(arr + 0, arr + n);
        return;
    }
    void Display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    void getLastOcc(int element)
    {
        int l = 0, mid, h = n - 1, res = -1;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (arr[mid] == element)
            {
                res = mid;
                l = mid + 1;
            }
            else if (arr[mid] > element)
            {
                h = mid - 1;
            }
            else if (arr[mid] < element)
            {
                l = mid + 1;
            }
        }
        if (res != -1)
        {
            cout << "Last Occurrence of " << element << " is at index : " << res << endl;
        }
        else
        {
            cout << "Element is Not present in the input array.\n";
        }
        return;
    }
    ~LastOccurrence()
    {
        delete[] arr;
        cout << "Code Terminated!\n";
    }
};

int main()
{
    int n, key;
    cout << "Enter the array size : ";
    cin >> n;
    LastOccurrence obj(n);
    cout << "Input Array : ";
    obj.Display();
    cout << "Enter the element : ";
    cin >> key;
    obj.getLastOcc(key);
    return 0;
}