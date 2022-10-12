/*
Problem Statement:Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Sample Test Cases:
3
Enter the Pattern: abdb
Pattern Does not match the string data.
Enter the Pattern: abba
Pattern is a Direct Match.
Enter the Pattern: abbc
Pattern Does not match the string data.
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

class WordPatternMatcher
{
    map<char, int> pattern2index;
    map<string, int> word2index;
    bool matchStatus;

protected:
    string data;
    string pattern;

public:
    WordPatternMatcher(string _data = "", string _pattern = "") : data(_data), pattern(_pattern), matchStatus(false) {}
    inline bool getMatchStatus() { return this->matchStatus; }
    inline void setdata(string _data = "", string _pattern = "")
    {
        this->data = _data;
        this->pattern = _pattern;
    }
    void Solve();
};

void WordPatternMatcher::Solve()
{
    istringstream input(data);
    int i = 0, N = pattern.size();
    string word = "";

    for (word; input >> word; i++)
    {
        if (i == N or (pattern2index[pattern[i]] != word2index[word]))
        {
            // miss match found between the character->index and word->index.
            this->matchStatus = false;
            return;
        }

        // update the mapping.
        pattern2index[pattern[i]] = i + 1;
        word2index[word] = i + 1;
    }
    this->matchStatus = (i == N);
    return;
}

int main()
{
    WordPatternMatcher Object;
    tests
    {
        string data, pattern;
        data = "dogs cat cat dogs";
        // getline(cin, data);
        std::cout << "\nEnter the Pattern: ";
        std::cin >> pattern;

        Object.setdata(data, pattern);
        Object.Solve();
        Object.getMatchStatus() ? std::cout << "Pattern is a Direct Match." : std::cout << "Pattern Does not match the string data.";
    }
    return 0;
}