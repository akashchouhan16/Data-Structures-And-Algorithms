#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
class SelectionSort
{
    int n;
    int *arr;

public:
    SelectionSort(int x = 5) : n(x)
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
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            k = i;
            for (j = i; j < n; j++)
            {
                if (*(arr + k) > *(arr + j))
                    k = j;
            }
            Swap(arr + i, arr + k);
        }
        return;
    }
    ~SelectionSort()
    {
        delete[] arr;
    }
};
int main()
{
    int size;
    cout << "Enter Size : ";
    cin >> size;
    SelectionSort obj(size);
    obj.Randomize();
    cout << "Input Array : ";
    obj.Display();
    obj.Sort();
    cout << "Output Array : ";
    obj.Display();
    return 0;
}
