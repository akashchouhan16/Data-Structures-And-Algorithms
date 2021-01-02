#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
template <class type>
class OrderAgnosticSearch
{
    int n;
    type *arr;

public:
    OrderAgnosticSearch(int size = 5) : n(size)
    {
        arr = new type[n];
    }
    void randomInput()
    {
        type n1, n2;
        cout << "Enter Range : ";
        cin >> n1 >> n2;
        srand(time(0));
        for (int i = 0; i < n; i++)
            arr[i] = n1 = rand() % (n2 - n1 + 1);
        int order = rand() % 2;
        if (order == 0) //Ascen
            sort(arr, arr + n);
        else if (order == 1) //Desc
            sort(arr, arr + n, greater<type>());
    }
    void binSearchAsc();
    void binSearchDesc();
    void Display();
    inline bool checkOrder()
    {
        if (arr[0] < arr[1])
            return true;
        return false;
    }
    ~OrderAgnosticSearch()
    {
        delete[] arr;
        cout << "Code Terminated!\n";
    }
};
template <class type>
void OrderAgnosticSearch<type>::Display()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <class type>
void OrderAgnosticSearch<type>::binSearchAsc()
{
    int l = 0, h = n, mid, res = -1;
    int key;
    cout << "Enter Search element : ";
    cin >> key;
    while (l < h)
    {
        mid = l = (h - l) / 2;
        if (*(arr + mid) == key)
        {
            res = mid;
        }
        else if (*(arr + mid) > key)
        {
            h = mid - 1;
        }
        else if (*(arr + mid) < key)
            l = mid + 1;
    }
    if (res != -1)
        cout << "Element Found at index " << res << endl;
    else
        cout << "Element Not Found in the array." << endl;
    return;
}
template <class type>
void OrderAgnosticSearch<type>::binSearchDesc()
{
    int l = 0, h = n, mid, res = -1;
    int key;
    cout << "Enter Search element : ";
    cin >> key;
    while (l < h)
    {
        mid = l = (h - l) / 2;
        if (*(arr + mid) == key)
        {
            res = mid;
        }
        else if (*(arr + mid) < key)
        {
            h = mid - 1;
        }
        else if (*(arr + mid) > key)
            l = mid + 1;
    }
    if (res != -1)
        cout << "Element Found at index " << res << endl;
    else
        cout << "Element Not Found in the array." << endl;
    return;
}

int main()
{
    int size;
    cout << "Enter Array size : ";
    cin >> size;
    OrderAgnosticSearch<int> obj(size);
    obj.randomInput();
    cout << "\nInput Array : ";
    obj.Display();
    if (obj.checkOrder())
        obj.binSearchAsc();
    else
        obj.binSearchDesc();

    return 0;
}