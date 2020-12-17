#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
class InsertionSort
{
    int n;
    int *arr;

public:
    InsertionSort(int x = 5) : n(x)
    {
        arr = new int[n];
    }
    void Randomize()
    {
        int r1, r2;
        srand(time(0));
        cout << "Enter input Range : ";
        cin >> r1 >> r2;
        for (int i = 0; i < n; i++)
            arr[i] = r1 + rand() % (r2 - r1 + 1);
        return;
    }
    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }
    void Swap(int *x, int *y)
    {
        *x = (*x) * (*y) / (*y = *x);
        return;
    }
    void Sort()
    {
        int x, j;
        for (int i = 1; i < n; i++)
        {
            x = *(arr + i);
            j = i - 1;
            while (j > -1 && arr[j] > x)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = x;
        }
        return;
    }
    ~InsertionSort()
    {
        delete[] arr;
    }
};
int main()
{
    int size;
    cout << "Enter Size : ";
    cin >> size;
    InsertionSort obj(size);
    obj.Randomize();
    cout << "Input Array : ";
    obj.Display();
    obj.Sort();
    cout << "Output Array : ";
    obj.Display();
    return 0;
}
