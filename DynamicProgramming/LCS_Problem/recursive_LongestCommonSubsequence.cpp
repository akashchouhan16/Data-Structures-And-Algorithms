#include "../headers.hpp"

/* Sample Test Case :
2
Enter Two Strings : abcdgh abedfhr
Enter Two Strings : axyezc sxecoq
case #1 : 4
case #2 : 3
*/
int LCS(string str1, string str2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (str1[n - 1] == str2[m - 1])
        return (1 + LCS(str1, str2, n - 1, m - 1));
    else
    {
        return max(LCS(str1, str2, n - 1, m), LCS(str1, str2, n, m - 1));
    }
}

int main()
{
    vi output;
    tests(t)
    {
        string str1, str2;
        cout << "Enter Two Strings : ";
        cin >> str1 >> str2;
        int n = str1.size(), m = str2.size();

        output.pb(LCS(str1, str2, n, m));
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}