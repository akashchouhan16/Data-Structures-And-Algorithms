// Petya organized a strange birthday party. He invited n friends and assigned an integer ki to the i-th of them. Now Petya would like to give a present to each of them. In the nearby shop there are m unique presents available, the j-th present costs cj dollars (1≤c1≤c2≤…≤cm). It's not allowed to buy a single present more than once.

// For the i-th friend Petya can either buy them a present j≤ki, which costs cj dollars, or just give them cki dollars directly.

// Help Petya determine the minimum total cost of hosting his party.

// Input
// The first input line contains a single integer t (1≤t≤103) — the number of test cases.

// The first line of each test case contains two integers n and m (1≤n,m≤3⋅105) — the number of friends, and the number of unique presents available.

// The following line contains n integers k1,k2,…,kn (1≤ki≤m), assigned by Petya to his friends.

// The next line contains m integers c1,c2,…,cm (1≤c1≤c2≤…≤cm≤109) — the prices of the presents.

// It is guaranteed that sum of values n over all test cases does not exceed 3⋅105, and the sum of values m over all test cases does not exceed 3⋅105.

// Output
// For each test case output a single integer — the minimum cost of the party.

// Examples
// input
// 2
// 5 4
// 2 3 4 3 2
// 3 5 12 20
// 5 5
// 5 4 3 2 1
// 10 40 90 160 250
// output
// 30
// 190
// input
// 1
// 1 1
// 1
// 1
// output
// 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>
#define ff                 first
#define ss                 second
#define ll                 long long
#define ii                 int, int
#define pii                pair<ii>
#define vi                 vector<int>
#define vvi                vector<vi>
#define si                 set<int>
#define vpii               vector<pii>
#define vs                 vector<string>
#define gi                 greater<int>
#define mii                map<ii>
#define maxheap            priority_queue<int>
#define minheap            priority_queue<int, vi, gi>
#define all(x)             x.begin(), x.end()
#define reverse(a)         reverse(all(a))
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define gcd                __gcd
#define mod                1000000007
#define PI                 3.14159265358979323846264338
#define inf                LONG_LONG_MAX
#define pcs(x,y)           fixed << setprecision(y) << x
#define lower(s)           transform(all(s), s.begin(),::tolower)
#define upper(s)           transform(all(s), s.begin(),::toupper)
#define FI(i,x,y,inc)      for(int i = x; i < y; i += inc)
#define F(i,x)             FI(i,0,x,1)
#define RF(i,n)            for(int i=n-1;i>=0;i--)
int XOR(int n) //  XOR OF 1 - N ELEMENTS
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}
using namespace std;








void solve() {


    ll n,m;
    cin>>n>>m;
    ll a[n],b[m];
    F(i,n) cin>>a[i];
    F(i,m) cin>>b[i];
    F(i,n){
        a[i]--;
    }
    F(i,n){
        a[i]=b[a[i]];
    }
    sort(a,a+n);
    //F(i,n) cout<<a[i]<<" ";
    ll s=0;
    ll i=0,j=n-1;
    ll k=0;
    while(i<=j){
        if(a[i]<=b[k]){
            s+=a[i];
            i++;
        }
        else{
            s+=b[k];
            j--;
            k++;
        }
    }
    cout<<s<<endl;



    return;


}




signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
