#ifndef Rotate
#define Rotate
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;
class RotateArray
{
protected:
    int n;
    int *arr;

public:
    RotateArray(int size = 5) : n(size)
    {
        arr = new int[n];
    }
    void RandomInput()
    {
        int n1, n2;
        cout << "Enter the Range : ";
        cin >> n1 >> n2;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            *(arr + i) = n1 + rand() % (n2 - n1 + 1);
        sort(arr, arr + n);
    }
    void RotateLeft(int steps)
    {
        while (steps--)
        {
            int temp = arr[0];
            for (int i = 0; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = temp;
        }
        return;
    }
    void RotateRight(int steps)
    {
        while (steps--)
        {
            int temp = arr[n - 1];
            for (int i = n - 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }
        return;
    }
};
#endif