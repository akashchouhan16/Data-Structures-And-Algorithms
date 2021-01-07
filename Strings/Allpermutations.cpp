#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Permutations
{
    int size;
    char *str;

public:
    Permutations(int x = 20) : size(x)
    {
        str = new char[size];
        cout << "Enter the string : ";
        cin.getline(str, size - 1);
    }
    inline char *getstring() { return str; }
    inline int getsize() { return size; }
    void swap(char *a, char *b)
    {
        char temp = *a;
        *a = *b;
        *b = temp;
        return;
    }
    void permute(char *str, int l, int r)
    {
        int i;
        if (l == r)
        {
            cout << str << ", ";
            return;
        }
        else
        {
            for (i = l; i <= r; i++)
            {
                swap(str + l, str + i);
                permute(str, l + 1, r);
                swap(str + l, str + i);
            }
        }
        return;
    }
    ~Permutations()
    {
        delete[] str;
        cout << "Code terminated!\n";
    }
};
int main()
{
    Permutations obj;
    obj.permute(obj.getstring(), 0, obj.getsize() - 1);
    return 0;
}