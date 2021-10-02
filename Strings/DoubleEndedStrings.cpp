/*
Problem Statement : You are given the strings a and b, consisting of lowercase Latin letters. You can do any number of the following operations in any order:
if |a|>0 (the length of the string a is greater than zero), delete the first character of the string a, that is, replace a with a2a3…an;
if |a|>0, delete the last character of the string a, that is, replace a with a1a2…an−1;
if |b|>0 (the length of the string b is greater than zero), delete the first character of the string b, that is, replace b with b2b3…bn;
if |b|>0, delete the last character of the string b, that is, replace b with b1b2…bn−1.
Note that after each of the operations, the string a or b may become empty.
For example, if a="hello" and b="icpc", then you can apply the following sequence of operations:
delete the first character of the string a ⇒ a="ello" and b="icpc";
delete the first character of the string b ⇒ a="ello" and b="cpc";
delete the first character of the string b ⇒ a="ello" and b="pc";
delete the last character of the string a ⇒ a="ell" and b="pc";
delete the last character of the string b ⇒ a="ell" and b="p".
For the given strings a and b, find the minimum number of operations for which you can make the strings a and b equal. Note that empty strings are also equal.
Sample Test Case:
5
a
a
abcd
bc
hello
codeforces
hello
helo
dhjakjsnasjhfksafasd
adjsnasjhfksvdafdser
O/P:
0
2
13
3
20
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string a, b;
	cin >> a >> b;
	if (a == b) {cout << 0 << endl; return;}
	int res = INT_MAX, ans = 0;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = a.length() - 1; j >= i; j--)
		{
			string temp = a.substr(i, j - i + 1);
			if ((b.find(temp)) != string::npos)
			{
				ans = (a.length() - temp.length()) + (b.length() - temp.length());
				res = min(res, ans);
			}
		}
	}
	if (res != INT_MAX)cout << res << endl;
	else cout << a.length() + b.length() << endl;
	return;
}
int32_t main()
{

	c_a_j();
	int t;cin>>t;
  for(int i=0;i<t;i++)
	{
		solve();
	}
	return 0;
}
