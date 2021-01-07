#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;
class MostFrequentChar
{
    string str;
    int *hashtable;

public:
    MostFrequentChar()
    {
        cout << "Enter String : ";
        getline(cin, str);
        hashtable = (int *)calloc(250, sizeof(int));
    }
    void updateHashTable()
    {
        int i = 0;
        while (str[i])
        {
            if (str[i] != ' ')
                hashtable[str[i]] += 1;
            i++;
        }
    }
    char getMax()
    {
        int i = 0, freq = 0;
        char max = '$';
        while (str[i++])
        {
            if (hashtable[str[i]] > freq)
            {
                freq = hashtable[str[i]];
                max = str[i];
            }
        }
        return max;
    }
    ~MostFrequentChar()
    {
        free(hashtable);
        cout << "Code Terminated!\n";
    }
};

int main()
{
    MostFrequentChar obj;
    obj.updateHashTable();
    char ch = obj.getMax();
    cout << "Most frequent Character in i/p string : " << ch << endl;
    return 0;
}