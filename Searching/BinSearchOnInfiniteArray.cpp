#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

class InfiniteArray
{
    int n;
    int *arr;

public:
    InfiniteArray()
    {
        n = 1 + rand() % 30;
        arr = new int[n];
    }
    InfiniteArray(int size) : n(size)
    {
        arr = new int[n];
    }

    void RandomInput()
    {
        int n1, n2;
        cout << "Enter Range : ";
        cin >> n1 >> n2;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            *(arr + i) = n1 + rand() % (n2 - n1 + 1);
        sort(arr, arr + n);
    }
    void Display();
    void UtilityforBinSearch(int l, int h, int key)
    {
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (*(arr + mid) == key)
            {
                cout << "Element Found at index " << mid << endl;
                return;
            }
            else if (*(arr + mid) < key)
            {
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        cout << "Element Not Found.\n";
        return;
    }
    void Search(int key);
    ~InfiniteArray()
    {
        delete[] arr;
        cout << "Code terminated!\n";
    }
};
void InfiniteArray ::Display()
{
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}
void InfiniteArray::Search(int key)
{
    int l = 0, h = n - 1;
    int val = *(arr);
    while (val < key)
    {
        l = h;
        h = 2 * h;
        val = *(arr + h);
    }
    UtilityforBinSearch(l, h, key);
}
int main()
{
    int n, key;
    InfiniteArray obj;

    obj.RandomInput();
    cout << "Input Array : ";
    obj.Display();
    cout << "Enter key element : ";
    cin >> key;
    obj.Search(key);
    return 0;
}