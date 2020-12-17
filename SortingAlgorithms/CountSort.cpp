#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class CountSort
{
    int *arr;

public:
    int n;
    CountSort(int s = 5) : n(s)
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
    int findMax()
    {
        int max = -65350;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
    void Sort()
    {
        int i, j = 0, *count;
        int max = findMax();
        count = (int *)malloc(sizeof(int) * (max + 1));
        for (i = 0; i < max + 1; i++)
        {
            count[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            count[arr[i]]++;
        }
        i = 0, j = 0;
        while (j < max + 1)
        {
            if (count[j] > 0)
            {
                arr[i++] = j;
                count[j]--;
            }
            else
                j++;
        }
    }
    ~CountSort()
    {
        delete[] arr;
    }
};

int main()
{
    int size;
    cout << "Enter the Array size : ";
    cin >> size;

    CountSort obj(size);
    obj.Randomize();
    cout << "Input Array  : ";
    obj.Display();
    cout << "Output Array : ";
    obj.Sort();
    obj.Display();
    return 0;
}