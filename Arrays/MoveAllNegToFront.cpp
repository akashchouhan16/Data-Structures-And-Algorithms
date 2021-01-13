// To Move All the Negative Numbers to front of the Array.
/*
    Enter size : 10
Enter upper limit : 2

Input : 0 -1 1 0 -1 0 1 0 0 0

Output : -1 -1 1 0 0 0 1 0 0 0
Code Terminated!
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

class MoveToFront
{
    int *arr;
    int size;

public:
    MoveToFront(int s = 10) : size(s)
    {
        arr = new int[size];
    }
    void input()
    {
        int n;
        srand(time(NULL));
        cout << "Enter upper limit : ";
        cin >> n;
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1 + rand() % (n + 1);
        }
        return;
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
            cout << *(arr + i) << " ";
        cout << endl;
    }
    inline void swap(int *x, int *y)
    {
        // *x = ((*x) * (*y)) / (*y = *x);
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void moveNegatives()
    {
        int l = 0, h = size - 1, mid = 0;
        while (mid <= h)
        {
            if (*(arr + mid) < 0)
            {
                swap(arr + l, arr + mid);
                l++;
                mid++;
            }
            else
            {
                mid++;
            }
        }
        return;
    }
    ~MoveToFront()
    {
        delete arr;
        cout << "Code Terminated!\n";
    }
};
int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;
    MoveToFront obj(size);
    obj.input();
    cout << "\nInput : ";
    obj.Display();
    obj.moveNegatives();
    cout << "\nOutput : ";
    obj.Display();
    return 0;
}