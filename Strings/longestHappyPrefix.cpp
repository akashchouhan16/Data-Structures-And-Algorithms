/* Problem Statement : A string is called a happy prefix 
if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s, return the longest happy prefix of s. Return an empty string "" 
if no such prefix exists. */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> lps(string& word)
{
    vector<int> lp(word.length(), 0);

    int index = 0;
    for (int i = 1; i < word.length();)
    {
        if (word[i] == word[index])
        {
            index++;
            lp[i] = index;
            i++;
        }
        else
        {
            if (index != 0)
                index = lp[index - 1];
            else
                i++;
        }
    }

    return lp;
}

string longestPrefix(string s) {
    vector<int> lp = lps(s);

    return s.substr(0, lp.back());
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    cout << longestPrefix(str) << endl;
    return 0;
}
