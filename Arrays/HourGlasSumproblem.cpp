//To Obtain the Max Hourglass Sum from a nXn 2D matrix.
#include <iostream>
#include <stdlib.h>

using namespace std;

class Hourglass
{
    int n;
    int **arr;

public:
    Hourglass()
    {
        cout << "Enter dimension : ";
        cin >> n;
        arr = (int **)malloc(sizeof(int) * 6);
        for (int i = 0; i < 6; i++)
        {
            arr[i] = new int[6];
        }
    }
    Hourglass(int dimen) : n(dimen)
    {
        arr = (int **)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
        }
        Input();
    }
    void Input()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cin >> arr[i][j];
            }
        }
        return;
    }
    void Display()
    {
        cout << "\nMatrix : ";
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << arr[i][j];
            }
        }
        return;
    }
    int maxSum()
    {
        int max_Sum = INT_MIN;
        int temp_Sum = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temp_Sum = 0;
                temp_Sum += arr[i][j];
                temp_Sum += arr[i][j + 1] + arr[i][j + 2];

                temp_Sum += arr[i + 1][j + 1];

                temp_Sum += arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

                if (temp_Sum > max_Sum || i == 0 && j == 0)
                {
                    max_Sum = temp_Sum;
                }
            }
        }
        return max_Sum;
    }
    // ~Hourglass()
    // {
    //     for (int i = 0; i < n; i++)
    //         delete[] arr[i];
    //     delete[] arr;
    // }
};

int main()
{
    Hourglass h1;
    h1.Input();
    h1.Display();
    cout << "\nMAx HourGlass Sum = " << h1.maxSum() << endl;
    return 0;
}