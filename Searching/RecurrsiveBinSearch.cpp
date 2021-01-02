#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

template <class type>
class BinSearch
{
    int n;
    type *arr;

public:
    BinSearch(int size = 3) : n(size)
    {
        arr = new type[n];
    }
    void RandomInput()
    {
        type n1, n2;
        cout << "Enter the Range : ";
        cin >> n1 >> n2;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            *(arr + i) = n1 + rand() % (n2 - n1 + 1);
        sort(arr, arr + n);
    }
    void Search(int l, int h, type key);
    void Display();
    ~BinSearch()
    {
        delete[] arr;
        cout << "Code Terminated!\n";
    }
};
template <class type>
void BinSearch<type>::Search(int l, int h, type key)
{

    int mid = l + (h - l) / 2;
    if (l <= h)
    {
        if (*(arr + mid) == key)
        {
            cout << "Element Found at index " << mid << endl;
            return;
        }
        else if (*(arr + mid) < key)
            Search(mid + 1, h, key);
        else if (*(arr + mid) > key)
            Search(l, mid - 1, key);
    }
    else
    {
        cout << "Element Not Found!\n";
        return;
    }
}
template <class type>
void BinSearch<type>::Display()
{
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}
int main()
{
    int size;
    cout << "Enter Array Size : ";
    cin >> size;
    BinSearch<int> obj(size);
    obj.RandomInput();
    cout << "Input Array : ";
    obj.Display();
    cout << "Enter Search Key : ";
    int key;
    cin >> key;
    obj.Search(0, size, key);
    return 0;
}