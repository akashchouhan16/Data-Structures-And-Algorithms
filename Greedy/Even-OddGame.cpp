// During their New Year holidays, Alice and Bob play the following game using an array a of n integers:

// Players take turns, Alice moves first.
// Each turn a player chooses any element and removes it from the array.
// If Alice chooses even value, then she adds it to her score. If the chosen value is odd, Alice's score does not change.
// Similarly, if Bob chooses odd value, then he adds it to his score. If the chosen value is even, then Bob's score does not change.
// If there are no numbers left in the array, then the game ends. The player with the highest score wins. If the scores of the players are equal, then a draw is declared.

// For example, if n=4 and a=[5,2,7,3], then the game could go as follows (there are other options):

// On the first move, Alice chooses 2 and get two points. Her score is now 2. The array a is now [5,7,3].
// On the second move, Bob chooses 5 and get five points. His score is now 5. The array a is now [7,3].
// On the third move, Alice chooses 7 and get no points. Her score is now 2. The array a is now [3].
// On the last move, Bob chooses 3 and get three points. His score is now 8. The array a is empty now.
// Since Bob has more points at the end of the game, he is the winner.
// You want to find out who will win if both players play optimally. Note that there may be duplicate numbers in the array.

// Input:-

// The first line contains an integer t (1≤t≤10^4) — the number of test cases. Then t test cases follow.

// The first line of each test case contains an integer n (1≤n≤2*10^5) — the number of elements in the array a.

// The next line contains n integers a1,a2,…,an (1≤ai≤10^9) — the array a used to play the game.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output:-

// For each test case, output on a separate line:

// "Alice" if Alice wins with the optimal play;
// "Bob" if Bob wins with the optimal play;
// "Tie", if a tie is declared during the optimal play.

// Example:-

// input
// 4
// 4
// 5 2 7 3
// 3
// 3 2 1
// 4
// 2 2 2 2
// 2
// 7 8
// output
// Bob
// Tie
// Alice
// Alice


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
#include <unordered_set>
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
using namespace std;


void solve() {
    int n;
    cin>>n;
    ll a[n];
    F(i,n) cin>>a[i];
    ll alice=0;
    ll bob=0;
    sort(a,a+n,greater<ll>());
    int i=0;
    while(i<n){
        if(i%2==0){
            if(a[i]%2==0){
                alice=alice+a[i];
            }
        }
        else{
            if(a[i]%2!=0){
                bob=bob+a[i];
            }
        }
        i++;
    }
    if(alice>bob){
        cout<<"Alice"<<endl;
    }
    else if(alice<bob){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Tie"<<endl;
    }
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
