#include <cstdlib>
#include <iostream>
#include "RotateArray.h"
using namespace std;
// Note : Right => Clockwise Rotation. and Left => Anti-clockwise Rotation.
class CicularSorted : public RotateArray
{
public:
    CicularSorted(int s) : RotateArray(s) {}
    void Display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void Search(int key)
    {
        int l = 0, h = n - 1, mid;
        while (l <= h)
        {
            mid = (h + l) / 2;
            if (*(arr + mid) == key)
            {
                cout << "Element Found at index " << mid << endl;
                return;
            }
            if (arr[mid] <= arr[h])
            {
                if (key > arr[mid] && key <= arr[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            else
            {
                if (key >= arr[l] && key < arr[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }
        cout << "Element Not Found!\n";
        return;
    }
};
int main()
{
    int size, key, steps, direction;
    cout << "Enter Array size : ";
    cin >> size;
    CicularSorted obj(size);
    obj.RandomInput();
    cout << "Input Array : ";
    obj.Display();
    cout << "Enter the direction and Number of Rotations (-1 for Left, +1 for Right) :";
    cin >> direction >> steps;
    if (direction == -1)
        obj.RotateLeft(steps);
    else if (direction == +1)
        obj.RotateRight(steps);
    cout << "After " << steps << " steps ";
    (direction == -1) ? cout << "Left Rotation..\n" : cout << "Right Rotation..\n";
    cout << "\nModified Input : ";
    obj.Display();
    cout << "Enter key : ";
    cin >> key;
    obj.Search(key);
    return 0;
}