#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Shell
{
    int *arr;

public:
    int n;
    Shell(int s = 5) : n(s)
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

    void Sort()
    {
        int temp, gap, i, j;
        for (int gap = n / 2; gap >= 1; gap /= 2)
        {
            for (int j = gap; j < n; j++)
            {
                int temp = arr[j];
                int i = j - gap;
                while (i >= 0 && arr[i] > temp)
                {
                    arr[i + gap] = arr[i];
                    i = i - gap;
                }
                arr[i + gap] = temp;
            }
        }
        return;
    }
    ~Shell()
    {
        delete[] arr;
    }
};

int main()
{
    int size;
    cout << "Enter the Array size : ";
    cin >> size;
    Shell obj(size);
    obj.Randomize();
    cout << "Input Array  : ";
    obj.Display();
    cout << "Output Array : ";
    obj.Sort();
    obj.Display();
    return 0;
}