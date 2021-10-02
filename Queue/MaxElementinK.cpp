/*
Problem  Statement : Given an array of n elements, find the maximum element in the array in every window of size k.
SAMPLE TEST CASE : 
I/P : 
5 3
5 2 4 1 6
O/P:
5 4 6
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a)cin >> i;
	deque<int> q;
	vector<int> ans;
	for (int i = 0; i < k; i++)         //basically finds the max element in 0 to k and stores
	{	//index of max element in start of dequeue.
		while (!q.empty() && a[q.back()] < a[i])
		{
			q.pop_back();
		}
		q.push_back(i);   //we push the indices in the dequeue from the back
	}
	ans.push_back(a[q.front()]);    //we push the max element in 0 to k from the given array
	for (int i = k; i < n; i++)    //then for rest of the elements in given array
	{
		if (q.front() == (i - k))    //if at the front the index present is out of the window,
			q.pop_front();           //then we remove this index from start using pop_front

		while (!q.empty() && a[q.back()] < a[i])  //again until we get smaller elements we keep
		{	//on popping elements from the dequeue from back.
			q.pop_back();
		}
		q.push_back(i);                //pushing indices in dequeue from the back
		ans.push_back(a[q.front()]);   //pushing the max element found in this window
	}

	for (auto x : ans)        //printing our final answer
		cout << x << " ";
	cout << "\n";
	return;
}
int32_t main()
{
#ifdef SIEVE
	sieve();
#endif
#ifdef NCR
	init();
#endif

	FIO
	c_a_j();

	solve();
	return 0;
}
