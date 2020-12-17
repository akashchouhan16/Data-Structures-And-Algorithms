#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
class QuickSort
{
protected:
    int *arr;

public:
    int n;
    QuickSort(int x = 5) : n(x)
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
    int partition(int l, int h)
    {
        int pivot = *(arr + l);
        int i = l, j = h;
        do
        {
            do
            {
                i++;
            } while (arr[i] <= pivot);
            do
            {
                j--;
            } while (arr[j] > pivot);

            if (i < j)
            {
                Swap(arr + i, arr + j);
            }
        } while (i < j);
        Swap(arr + j, arr + l);
        return j;
    }
    void quickSort(int l, int h)
    {
        if (l < h)
        {
            int p = partition(l, h);
            quickSort(l, p);
            quickSort(p + 1, h);
        }
        return;
    }
    ~QuickSort()
    {
        delete[] arr;
    }
};
int main()
{
    int size;
    cout << "Enter Size : ";
    cin >> size;
    QuickSort obj(size);
    obj.Randomize();
    cout << "Input Array : ";
    obj.Display();
    obj.quickSort(0, obj.n);
    cout << "Output Array : ";
    obj.Display();
    return 0;
}
