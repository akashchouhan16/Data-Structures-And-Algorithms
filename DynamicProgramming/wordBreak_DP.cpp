/*Problem Statement : Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
Note: From the dictionary B each word can be taken any number of times and in any order.
Sample Test Case :
3
sunsets
Input the dataSet[] strings : i like ilike sun rise sets tim jack exit
telepathy
Input the dataSet[] strings : tele phone mobile phone ice cream icecream exit
wordplay
Input the dataSet[] strings : play work word break exit
case #1 : YES
case #2 : YES
case #3 : YES
*/

#include "headers.hpp"
#include <unordered_map>

using namespace std;
void inputCollection(v(string) & dataSet)
{
    cout << "Input the dataSet[] strings : ";
    string temp;
    do
    {
        cin >> temp;
        if (temp == "exit" || temp == "Exit" || temp == "EXIT")
            break;
        dataSet.pb(temp);
    } while (temp != "exit" || temp != "Exit" || temp != "EXIT");
}
map<string, int> dp;
int wordBreak(string word, v(string) & dataSet)
{
    int n = word.size();
    if (n == 0)
        return 1;
    if (dp[word] != 0)
        return dp[word];

    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        string temp = word.substr(0, i);
        for (int j = 0; j < dataSet.size(); ++j)
        {
            if (temp.compare(dataSet[j]) == 0)
            {
                flag = true; //word found.
                break;
            }
        }
        if (flag and wordBreak(word.substr(i, n - i), dataSet) == 1)
            return dp[word] = 1;
    }
    return dp[word] = -1; //Not Found.
}
int main()
{
    v(string) output;
    tests(t)
    {
        string word;
        v(string) dataSet; //Collection of strings.
        cin >> word;
        inputCollection(dataSet);
        output.pb(wordBreak(word, dataSet) ? "YES" : "NO");
    }
    loop(i, output.size()) cout << "case #" << i + 1 << " : " << output[i] << endl;
    return 0;
}