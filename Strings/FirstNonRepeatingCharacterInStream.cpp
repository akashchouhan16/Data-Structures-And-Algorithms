/*Problem Statement: Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.

Sample Test Case
3
aaabc
geekg
zz
Case #1: a##bb
Case #2: ggggk
Case #3: z#
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>

#define INF INT_MAX
#define MOD 1e9 + 7
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define pp() pop_back()
#define loop(i, n) for (int i = 0; i < n; i++)
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

string Solve(string &str, int n)
{
    string res = "";
    if (n == 0)
        return "";
    v(int) visited(26, 0);
    v(char) stream;

    loop(i, n)
    {
        if (not visited[str[i] - 'a'])
        {
            stream.pb(str[i]);
        }
        visited[str[i] - 'a']++;
        bool flag = false;
        int m = stream.size();
        loop(j, m)
        {
            if (visited[stream[j] - 'a'] == 1)
            {
                res += stream[j];
                flag = true;
                break;
            }
        }
        if (!flag)
            res += '#';
    }
    return res;
}
signed main()
{
    v(string) out;
    tests
    {
        string str;
        cin >> str;
        int len = str.size();
        out.pb(Solve(str, len));
    }

    loop(i, out.size()) cout << "Case #" << i + 1 << ": " << out[i] << endl;

    return 0;
}