#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Palindrome
{
    int n;
    char *str;

public:
    Palindrome(int x = 5) : n(x)
    {
        char temp[10];
        cout << "Enter the string : ";
        cin >> temp;
        str = new char[strlen(temp)];
        strcpy(str, temp);
    }
    bool check(char *temp)
    {
        int i = 0;
        while (i < n)
        {
            i++;
            if (temp[i] != str[i])
                return false;
        }
        return true;
    }
    void checkPalindrome() //No Need.
    {
        char *temp = new char[n];
        for (int i = n - 1; i >= 0; i--)
        {
            temp[i] = str[i];
        }
        for (int i = n - 1; i >= 0; i--)
            cout << str[i];
        cout << endl;
        cout << "\n temp :  " << temp << endl;
        if (check(temp))
            cout << "Input string is a Palindromic a string.\n";
        else
            cout << "Input string is not a Palindromic string.\n";
        delete[] temp;
        return;
    }
    void Checkpalindrome()
    {
        int i = 0, j = n - 1;
        for (; i < n, j >= 0; i++, j--)
        {
            if (str[i] != str[j])
            {
                cout << "Not Palindromic!\n";
                return;
            }
        }
        cout << "Palindromic string!\n";
        return;
    }
    ~Palindrome()
    {
        delete[] str;
        cout << "Code Terminated!\n";
    }
};
int main()
{
    Palindrome obj;
    obj.Checkpalindrome();
    return 0;
}