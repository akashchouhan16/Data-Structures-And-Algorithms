#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template <class type>
class ZeroSumTriplet
{
    vector<type> arr;
    int maxCap;

public:
    ZeroSumTriplet()
    {
        cout << "Enter max required capacity : ";
        cin >> maxCap;
        randomInput();
    }
    void randomInput()
    {
        type n1, n2;
        cout << "Enter range : ";
        cin >> n1 >> n2;
        for (int i = 0; i < maxCap; i++)
            arr.push_back(n1 + rand() % (n2 - n1 + 1));
    }
    void Display()
    {
        for (auto &x : arr)
            cout << x << " ";
        cout << endl;
    }
    // Inefficient Solution of O(n^3).
    bool getTripletwithZeroSum()
    {
        int i, j, k;
        for (i = 0; i < maxCap - 2; i++)
        {
            for (j = i + 1; j < maxCap - 1; j++)
            {
                for (k = j + 1; k < maxCap; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        cout << "Triplet with Sum zero : " << arr[i] << "," << arr[j] << "," << arr[k] << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    ZeroSumTriplet<int> obj;
    cout << "Input Vector: ";
    obj.Display();
    bool check = obj.getTripletwithZeroSum();
    if (!check)
        cout << "Triplet with Zero sum not found!\n";
    return 0;
}