/* Problem Statement : You are given a string s. You can convert s to a palindrome 
by adding characters in front of it.Return the shortest palindrome you can 
find by performing this transformation.*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string l = s + "#" + rev_s;

    vector<int> p(l.size(), 0);
    for (int i = 1; i < l.size(); i++) {
        int j = p[i - 1];
        while (j > 0 && l[i] != l[j])
            j = p[j - 1];
        p[i] = (j += l[i] == l[j]);
    }

    return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    cout << shortestPalindrome(str) << endl;
    return 0;
}
