//Given a string find the longest palindromic substring in the given string. 
//Test case-1:  str = "abccbad" output:"The longest palindromic sub string is abccba"
//Test-case-2:  str = "abacdba" output:"The longest palindromic sub string is aba"
//!!! Notice that the problem statement asks us to find substring, so the answer in test case 2 is 'aba'. If the question is to find a subsequence then the answer would be 'abcba'

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int expandAroundCenter(string s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

string longestPalindrome(string s) {
    if (s == "" || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);       // Checking for odd length palindrome (ex: abcba)
        int len2 = expandAroundCenter(s, i, i + 1);   // Checking for even length palindrome (ex: abba)
        int len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end -start+ 1);
}

int main()
{
    string s;
    cin >> s;
    cout <<"The longest palindromic sub string is "<< longestPalindrome(s);
    return 0;
}

