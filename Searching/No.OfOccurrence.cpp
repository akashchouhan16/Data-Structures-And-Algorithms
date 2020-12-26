#include <bits/stdc++.h>
#include "Utility.h"
using namespace std;

class NumberOfOccerrence : public Utility
{
    // Utility Class takes care of inputs and data members.
public:
    NumberOfOccerrence(int size) : Utility(size)
    { /*Base Init.*/
    }
    void OccurenceCount()
    {
        int key, count = 0;
        cout << "Enter key element : ";
        cin >> key;
        count = getLastOcc(key) - getFirstOcc(key) + 1;
        cout << "Element " << key << " has occurred " << count << " times.\n";
    }
    void Display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
};

int main()
{
    int size;
    cout << "Enter the Array Size : ";
    cin >> size;
    NumberOfOccerrence obj(size);
    cout << "Input Array : ";
    obj.Display();
    obj.OccurenceCount();
    return 0;
}