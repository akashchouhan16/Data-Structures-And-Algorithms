#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class ConvertCase
{
    char str[15];

public:
    ConvertCase()
    {
        cout << "Enter string : ";
        gets(str);
    }
    void Convert()
    {
        // for (char x : str)
        // {
        //     if (int(x) >= 65 && int(x) <= 90)
        //         x += 32;
        //     else
        //         x -= 32;
        // }
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
                str[i] = str[i] + 32;
            else
                str[i] -= 32;
        }
        cout << "\nNew String : " << str << endl;
    }
};

int main()
{
    ConvertCase obj;
    obj.Convert();
    return 0;
}