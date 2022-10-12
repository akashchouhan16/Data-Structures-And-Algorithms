#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define ull             unsigned long long int
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vii             vector<int,int>
#define vpii            vector<pair<int,int>>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define yes             cout<<"YES"<<endl;
#define no              cout<<"NO"<<endl;
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dec(n,v)        int n; cin>>n; vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
#define decl(n,v)       int n; cin>>n; vector<int> v(n+1);for(int i=1;i<=n;i++)cin>>v[i];
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void c_a_j()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int FastExp(int a, int n)
{
	if (n == 0)return 1;
	int x = FastExp(a, n / 2);         //subproblem

	if (n & 1)                         // if n is odd
	{
		return a * x * x;             //a^n = a*(a^n/2)^2;
	}
	return x * x;                    //a^n = (a^n/2)^2;
}
void solve()
{
	int a, n;
	cin >> a >> n;
	cout << FastExp(a, n) << "\n";
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