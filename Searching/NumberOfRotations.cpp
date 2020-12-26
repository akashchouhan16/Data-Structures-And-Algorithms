#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

template <class T>
class SortedRotated
{
    int size;
    T arr;

public:
        SortedRotated(int n=5):size(n{
        arr = new T[size];}
        void RandomInput(){
        int n1, n2;
        cout << "Enter range(n1 to n2) : ";
        cin >> n1 >> n2;
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = n1 + rand() % (n2 - n1 + 1);
        }
        sort(arr.begin(), arr.end());
        return;
        }
        void Display(){
        for (auto x : arr)
        {
            cout << c << " ";
        }
        cout << endl;
        return;
        }
        void NoOfRotattions(){
        int count = 0;
        int min = 65535;
        for (auto x : arr)
        {
            if (x < min)
            {
                min = x;
            }
        }
        }
};