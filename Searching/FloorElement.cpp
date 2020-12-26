#include <bits/stdc++.h>
using namespace std;

class Floor
{
    int *arr;
    int size;

public:
    Floor(int n = 5) : size(n)
    {
        arr = new int[size];
        randomInput();
    }
    void randomInput()
    {
        int n1, n2;
        cout << "Enter Element Range(n1 to n2) : ";
        cin >> n1 >> n2;
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = n1 + rand() % (n2 - n1 + 1);
        }
        std::sort(arr + 0, arr + size);
        return;
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
            cout << *(arr + i) << " ";
        cout << endl;
    }
    void GetFloor(int element)
    {
        int l = 0, h = size - 1, mid, res = -1;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (arr[mid] == element)
            {
                res = arr[mid];
                break;
            }
            else if (arr[mid] > element)
            {
                h = mid - 1;
            }
            else if (arr[mid] < element)
            {
                l = mid + 1;
                res = arr[mid];
            }
        }
        if (res != -1)
            cout << "Floor of " << element << " is " << res << "." << endl;
        return;
    }
    ~Floor()
    {
        delete[] arr;
        cout << "Code Terminated!\n";
    }
};

int main()
{
    int n, element;
    cout << "Enter Array size : ";
    cin >> n;
    Floor obj(n);
    cout << "Input Array : ";
    obj.Display();
    cout << "Enter the Element whose Floor is to be Found out : ";
    cin >> element;
    obj.GetFloor(element);
    return 0;
}