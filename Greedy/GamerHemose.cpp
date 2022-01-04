// One day, Ahmed_Hossam went to Hemose and said "Let's solve a gym contest!". Hemose didn't want to do that, as he was playing Valorant, so he came up with a problem and told it to Ahmed to distract him. Sadly, Ahmed can't solve it... Could you help him?

// There is an Agent in Valorant, and he has n weapons. The i-th weapon has a damage value ai, and the Agent will face an enemy whose health value is H.

// The Agent will perform one or more moves until the enemy dies.

// In one move, he will choose a weapon and decrease the enemy's health by its damage value. The enemy will die when his health will become less than or equal to 0. However, not everything is so easy: the Agent can't choose the same weapon for 2 times in a row.

// What is the minimum number of times that the Agent will need to use the weapons to kill the enemy?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤105). Description of the test cases follows.

// The first line of each test case contains two integers n and H (2≤n≤103,1≤H≤109) — the number of available weapons and the initial health value of the enemy.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the damage values of the weapons.

// It's guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

// Output
// For each test case, print a single integer — the minimum number of times that the Agent will have to use the weapons to kill the enemy.

// Example
// input
// 3
// 2 4
// 3 7
// 2 6
// 4 2
// 3 11
// 2 1 7
// output
// 1
// 2
// 3
// Note
// In the first test case, the Agent can use the second weapon, making health value of the enemy equal to 4−7=−3. −3≤0, so the enemy is dead, and using weapon 1 time was enough.

// In the second test case, the Agent can use the first weapon first, and then the second one. After this, the health of enemy will drop to 6−4−2=0, meaning he would be killed after using weapons 2 times.

// In the third test case, the Agent can use the weapons in order (third, first, third), decreasing the health value of enemy to 11−7−2−7=−5 after using the weapons 3 times. Note that we can't kill the enemy by using the third weapon twice, as even though 11−7−7<0, it's not allowed to use the same weapon twice in a row.

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


    ll n,h;
    cin>>n>>h;
    ll arr[n];
    F(i,n) cin>>arr[i];
    sort(arr,arr+n);
    ll s=0;
    s=arr[n-1]+arr[n-2];
    ll c=h/s;
    ll sum=c*s;
    if(sum==h){cout<<(c*2)<<endl;}\
    else if(sum+arr[n-1]>=h) cout<<(c*2)+1<<endl;
    else cout<<(c*2)+2<<endl;


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

