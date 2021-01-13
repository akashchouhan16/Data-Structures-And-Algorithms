#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

template <class type>
class MaxProductSubArray
{
    vector<type> vec;
    int maxCap;

public:
    MaxProductSubArray()
    {
        type n1, n2;
        cout << "Enter max required Vector capacity : ";
        cin >> maxCap;
        cout << "Enter Range of Elements : ";
        cin >> n1 >> n2;
        srand(time(NULL));
        for (int i = 0; i < maxCap; i++)
        {
            vec.push_back(n1 + rand() % (n2 - n1 + 1));
        }
    }
    void Display()
    {
        for (auto &c : vec)
            cout << c << " ";
        cout << endl;
    }
    type MaxProduct()
    {
        type Final_max = vec[0], curr_max = vec[0], curr_min = vec[0];
        for (int x = 0; x < maxCap; x++)
        {
            type temp = curr_max;
            curr_max = max(max(curr_max * vec[x], curr_min * vec[x]), vec[x]);
            curr_min = min(min(temp * vec[x], curr_min * vec[x]), vec[x]);
            if (Final_max < curr_max)
                Final_max = curr_max;
        }
        return Final_max;
    }
};

int main()
{
    MaxProductSubArray<int> obj;
    cout << "Input Vector : ";
    obj.Display();
    cout << "\nMax Product : " << obj.MaxProduct() << endl;
    return 0;
}
