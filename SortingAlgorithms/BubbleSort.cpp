#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
class BubbleSort
{
    int n;
    int *arr;

public:
    BubbleSort(int x = 5) : n(x)
    {
        arr = new int[n];
    }
    void Randomize()
    {
        int r1, r2;
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
    void Bubble()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int flag = 0;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (*(arr + j) > *(arr + j + 1))
                {
                    Swap(arr + j, arr + j + 1);
                    flag = 1;
                }
            }
            if (!flag)
                break;
        }
        return;
    }
    ~BubbleSort()
    {
        delete[] arr;
    }
};
int main()
{
    int size;
    cout << "Enter Size : ";
    cin >> size;
    BubbleSort obj(size);
    obj.Randomize();
    cout << "Input Array : ";
    obj.Display();
    obj.Bubble();
    cout << "Output Array : ";
    obj.Display();
    return 0;
}
