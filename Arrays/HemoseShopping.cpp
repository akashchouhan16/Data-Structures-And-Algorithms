/*
Problem Statement : Hemose was shopping with his friends Samez, AhmedZ, AshrafEzz, TheSawan and O_E in Germany. As you know, Hemose and his friends are problem solvers, so they are
very clever. Therefore, they will go to all discount markets in Germany.
Hemose has an array of n integers. He wants Samez to sort the array in the non-decreasing order. Since it would be a too easy problem for Samez, Hemose allows Samez to use only the
following operation:
Choose indices i and j such that 1≤i,j≤n, and |i−j|≥x. Then, swap elements ai and aj.
Can you tell Samez if there's a way to sort the array in the non-decreasing order by using the operation written above some finite number of times (possibly 0)?

Sample Test Case-

I/P:
4
3 3
3 2 1
4 3
1 2 3 4
5 2
5 1 2 3 4
5 4
1 2 3 4 4
O/P:
NO
YES
YES
YES
*/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	vector<int> temp = v;
	sort(all(v));

	for (int i = 0; i < n; i++)
	{
		if ((i + x) < n || (i - x) >= 0)continue;
		if (v[i] != temp[i])
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int32_t main()
{
  int t;cin>>t;
  while(t--)solve();
	return 0;
}
