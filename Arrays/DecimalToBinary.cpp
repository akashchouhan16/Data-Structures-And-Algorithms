#include <iostream>
#include <stdlib.h>
using namespace std;

class Binary
{
    int n;

public:
    Binary(int decimal = 5) : n(decimal) {}
    int countMaxConsecutiveOne(int *temp, int n)
    {
        int j = 0, max = -1, curr = 1;
        for (int i = 0; i < n; i++)
        {
            if (temp[i] == 1)
            {
                j = i;
                while (temp[j] == 1)
                {
                    curr++;
                    if (curr > max)
                        max = curr;
                    j++;
                }
            }
            //Reset current.
            curr = 0;
        }
        return max;
    }
    void Solution()
    {
        int binaryArray[32];
        int i = 0;
        while (n > 0)
        {
            binaryArray[i] = n % 2;
            n = n / 2;
            i++;
        }
        int j, temp[i];
        cout << "Binary Equivalent : ";
        for (j = i - 1; j >= 0; j--)
            cout << binaryArray[j];
        cout << endl;
        for (j = i - 1; j >= 0; j--)
            temp[j] = binaryArray[j];
        for (int k = 0; k <= i - 1; k++)
            cout << temp[k];
        cout << endl;
        int max = countMaxConsecutiveOne(temp, j);
        cout << "Max 1s = " << max << endl;
        return;
    }
};
int main()
{
    int dec;
    cout << "Enter Decima l number  :";
    cin >> dec;
    Binary bin(dec);
    bin.Solution();
    return 0;
}