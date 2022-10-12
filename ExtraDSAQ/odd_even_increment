#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define all(v)          v.begin(),v.end()
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// for debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//some maths
int M;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return (a * b) / gcd(a, b); }
inline int Mod(int x) { return (x % M + M) % M; }
inline int add_Mod(int a, int b) {return Mod(Mod(a) + Mod(b));}
inline int sub_Mod(int a, int b) {return Mod(Mod(a) - Mod(b) + M);}
inline int mul_Mod(int a, int b) {return Mod(Mod(a) * Mod(b));}
inline int FastModExp(int a, int b) {M = mod; int res = 1; while (b > 0) {if (b & 1)res = mul_Mod(res, a); a = mul_Mod(a, a); b = b >> 1;} return res;}
inline int mmi(int y) { return FastModExp(y, M - 2);}
inline int div_Mod(int a, int b) { return mul_Mod(a, mmi(b));}
inline void extendedEuclidMethod(int a, int b, int &x, int &y) { if (b == 0) {x = 1; y = 0; return;} extendedEuclidMethod(b, a % b, x, y); int cX = y; int cY = x - (a / b) * y; x = cX; y = cY;}

void c_a_j()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v)cin >> x;
    for (int i = 2; i < n; i++)
    {
        if (v[i] % 2 != v[i % 2] % 2)
        {cout << "NO\n"; return;}
    }
    cout << "YES\n";
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

    w(x)solve();
    return 0;
}
