#include <iostream>
#include <stdlib.h>

using namespace std;
void input(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    return;
}
void Display(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return;
}

int DiagonalDifference(int **arr, int n)
{
    int major = 0, minor = 0, i = 0, j = 0, k = n - 1;
    while (i < n && j < n && k >= 0)
    {
        major += arr[i++][j];
        minor += arr[k--][j];
        j++;
    }
    int diff = major - minor;
    return (diff > 0) ? diff : -diff;
}
int main()
{
    int n;
    cout << "Enter the Dimention (n) of the Square Marix : ";
    cin >> n;
    int **arr;
    arr = (int **)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    cout << "Enter the matrix elements  :\n";
    input(arr, n);
    cout << "\n\nInput Matrix : ";
    Display(arr, n);
    cout << "\nDiagonal Difference = " << DiagonalDifference(arr, n) << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete arr;

    return 0;
}
