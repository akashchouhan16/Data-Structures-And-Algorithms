#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution
{
    string data;

public:
    Solution()
    {
        cout << "Enter String : ";
        getline(cin, data);
        RemoveSpaces();
        cout << "Spaces Removed..\n";
        cout << "Output String : " << data << endl;
    }
    void RemoveSpaces()
    {
        int i = 0, j = 0;
        while (data[i])
        {
            if (data[i] != ' ')
                data[j++] = data[i];
            i++;
        }
        return;
    }
};
int main()
{
    Solution obj;
    return 0;
}