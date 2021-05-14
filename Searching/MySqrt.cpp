// Square Root Method Implementation in O(NLogN) : FB Interview Question Set.
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class MathFunctions
{
protected:
    long int num;
    long int output;

public:
    MathFunctions()
    {
        cout << "Enter the Number : ";
        cin >> this->num;
        this->output = 0;
    }
};

class SQRT : public MathFunctions
{
public:
    SQRT() {}
    inline long int getNum() { return this->num; }
    int Compute()
    {
        long int low = 0, high = this->num / 2;
        long int mid = 0;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if ((mid * mid) == (num))
                return mid;
            else if ((mid * mid) > num)
            {
                high--;
            }
            else
                low++;
        }
        cout << "Unable to Compute SQRT of " << num << endl;
        return -1;
    }
};

class CubeRT : public MathFunctions
{
public:
    inline long int getNum() { return this->num; }
    int Compute()
    {
        long int low = 0, high = this->num / 2;
        long int mid = 0;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (int(pow(mid, 3)) == num)
            {
                return mid;
            }
            else if (int(pow(mid, 3)) > num)
                high--;
            else
                low++;
        }
        cout << "Unable to Compute the Cube Root of " << num << endl;
        return -1;
    }
};

int main()
{
    SQRT S;
    cout << "SQRT(" << S.getNum() << ") = " << S.Compute();
    cout << endl;

    CubeRT C;
    cout << "Cube Root(" << C.getNum() << ") = " << C.Compute() << endl;

    return 0;
}