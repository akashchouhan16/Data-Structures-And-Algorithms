#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
class MergeSort
{
protected:
    int *arr;

public:
    int n;
    MergeSort(int x = 5) : n(x)
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
    void Merge(int l, int mid, int h)
    {
        int temp[100];
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= h)
        {
            if (*(arr + i) < *(arr + j))
            {
                temp[k++] = arr[i++];
            }
            else
                temp[k++] = arr[j++];
        }

        for (; i <= mid; i++)
            temp[k++] = arr[i++];
        for (; j <= h; j++)
            temp[k++] = arr[j++];
        for (int p = l; p <= h; p++)
            arr[p] = temp[p];
        return;
    }
    void mergeSort()
    {
        int i, p, l, h, mid;
        for (p = 2; p <= n; p = p * 2)
        {
            for (i = 0; i + p - 1 < n; i = i + p)
            {
                l = i;
                h = i + p - 1;
                mid = (l + h) / 2;
                Merge(l, mid, h);
            }
        }
        if (p / 2 < n) //for odd n.
            Merge(0, (p / 2) - 1, n - 1);
    }
    ~MergeSort()
    {
        delete[] arr;
    }
};
int main()
{
    int size;
    cout << "Enter Size : ";
    cin >> size;
    MergeSort obj(size);
    obj.Randomize();
    cout << "Input Array : ";
    obj.Display();
    obj.mergeSort();
    cout << "Output Array : ";
    obj.Display();
    return 0;
}
