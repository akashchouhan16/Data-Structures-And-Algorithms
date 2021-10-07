// Do you know a story about the three musketeers? Anyway, you will learn about its origins now.

// Richelimakieu is a cardinal in the city of Bearis. He is tired of dealing with crime by himself. He needs three brave warriors to help him to fight against bad guys.

// There are n warriors. Richelimakieu wants to choose three of them to become musketeers but it's not that easy. The most important condition is that musketeers must know each other to cooperate efficiently. And they shouldn't be too well known because they could be betrayed by old friends. For each musketeer his recognition is the number of warriors he knows, excluding other two musketeers.

// Help Richelimakieu! Find if it is possible to choose three musketeers knowing each other, and what is minimum possible sum of their recognitions.

// Input
// The first line contains two space-separated integers, n and m (3 ≤ n ≤ 4000, 0 ≤ m ≤ 4000) — respectively number of warriors and number of pairs of warriors knowing each other.

// i-th of the following m lines contains two space-separated integers ai and bi (1 ≤ ai, bi ≤ n, ai ≠ bi). Warriors ai and bi know each other. Each pair of warriors will be listed at most once.

// Output
// If Richelimakieu can choose three musketeers, print the minimum possible sum of their recognitions. Otherwise, print "-1" (without the quotes).

// Examples
// input
// 5 6
// 1 2
// 1 3
// 2 3
// 2 4
// 3 4
// 4 5
// output
// 2
// input
// 7 4
// 2 1
// 3 6
// 5 1
// 1 7
// output
// -1

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






void dfs(int i,vector<int>adj[],int n,int &m){
    int a=i;
    for(auto x:adj[i]){
        int b=x;
        for(int j=1;j<=n;j++){
            int flag=0;
            for(auto y:adj[j]){
                if(y==a) flag++;
                else if(y==b) flag++;
            }
            if(flag==2){
                int sum=adj[a].size()-2+adj[b].size()-2+adj[j].size()-2;
                m=min(m,sum);
            }
        }

    }
}

void solve() {


    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ma=INT_MAX;
    for(int i=1;i<=n;i++){
        dfs(i,adj,n,ma);
    }
    if(ma==INT_MAX) cout<<-1<<endl;
    else cout<<ma<<endl;

    return;


}




signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
        solve();
    
    return 0;
}
