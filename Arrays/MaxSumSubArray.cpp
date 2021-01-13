#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
template <class type>
class MaxSum
{
    vector<type> vec;
    int size;

public:
    MaxSum()
    {
        cout << "Enter Max Size : ";
        cin >> size;
    }
    void randomInput()
    {
        type n1, n2;
        cout << "Enter Range : ";
        cin >> n1 >> n2;
        srand(time(NULL));
        for (int i = 0; i < size; i++)
            vec.push_back(n1 + rand() % (n2 - n1 + 1));
        return;
    }
    void Display()
    {
        for (auto &x : vec)
            cout << x << " ";
        cout << endl;
    }
    void getMaxSumSubarray()
    {
        type max = -1, curr = 0;
        for (int i = 0; i < size; i++)
        {
            curr += vec[i];
            if (curr > max)
            {
                max = curr;
            }
            if (curr < 0)
                curr = 0;
        }
        cout << "Max Sum of a Subarray : " << max << endl;
        return;
    }
};

int main()
{
    MaxSum<int> obj;
    obj.randomInput();
    cout << "Input Vector : ";
    obj.Display();
    cout << endl;
    obj.getMaxSumSubarray();
    return 0;
}