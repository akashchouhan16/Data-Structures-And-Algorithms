#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

void EncryptData(string Text, int shift)
{
    string result = "";
    for (int i = 0; i < Text.length(); i++)
    {
        if (isupper(Text[i]))
        {
            result += char(int(Text[i] + shift - 65) % 26 + 65);
        }
        else
        {
            result += char(int(Text[i] + shift - 97) % 26 + 97);
        }
    }
    cout << result << endl;
}
int main()
{
    string str;
    int shifts;
    cout << "Enter Text : ";
    getline(cin, str);
    cout << "Enter the Number of Shifts Required : ";
    cin >> shifts;
    cout << "Encypter Text : ";
    EncryptData(str, shifts);
    return 0;
}