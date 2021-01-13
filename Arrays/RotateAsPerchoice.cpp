#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

template <class type>
class Rotate
{
    type *arr;
    int size;

public:
    Rotate(int s = 10) : size(s)
    {
        int c;
        cout << "Array of size " << size << " will be created..\n update?(1/0) : ";
        cin >> c;
        if (c == 1)
        {
            cout << "Enter new size : ";
            cin >> size;
        }
        arr = new type[size];
        randomSortedInput();
        sort(arr, arr + size);
    }
    void randomSortedInput()
    {
        type n1, n2;
        cout << "Enter Range : ";
        cin >> n1 >> n2;
        for (int i = 0; i < size; i++)
            arr[i] = n1 + rand() % (n2 - n1 + 1);
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
            cout << *(arr + i) << " ";
        cout << endl;
    }
    void RotateLeft(int shifts)
    {
        while (shifts--)
        {
            type temp = arr[0];
            for (int i = 0; i < size - 1; i++)
                arr[i] = arr[i + 1];
            arr[size - 1] = temp;
        }
        return;
    }
    void RotateRight(int shifts)
    {
        while (shifts--)
        {
            type temp = arr[size - 1];
            for (int i = size - 2; i >= 0; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[0] = temp;
        }
        return;
    }
    void choice()
    {
        int ch, shifts;
        do
        {
            cout << "Enter Choice : ";
            cin >> ch;
            if (ch == -1)
            {
                cout << "Enter the no. of (Left)shifts : ";
                cin >> shifts;
                RotateLeft(shifts);
                Display();
            }
            else if (ch == 1)
            {
                cout << "Enter the no. of (Right)shifts : ";
                cin >> shifts;
                RotateRight(shifts);
                Display();
            }
            else
            {
                if (ch != 0)
                    cout << "Invalid Choice..\n";
                else
                    break;
            }
        } while (ch != 0);
        return;
    }
    ~Rotate()
    {
        delete[] arr;
        cout << "Code Terminated!\n";
    }
};

int main()
{
    Rotate<int> obj;
    cout << "Input : ";
    obj.Display();
    cout << "Enter -1 For Left Shift | Enter 1 for Right Shift | Enter 0 to exit().\n";
    obj.choice();
    return 0;
}