// After a hard day Vitaly got very hungry and he wants to eat his favorite potato pie. But it's not that simple. Vitaly is in the first room of the house with n room located in a line and numbered starting from one from left to right. You can go from the first room to the second room, from the second room to the third room and so on — you can go from the (n - 1)-th room to the n-th room. Thus, you can go to room x only from room x - 1.
// The potato pie is located in the n-th room and Vitaly needs to go there.
// Each pair of consecutive rooms has a door between them. In order to go to room x from room x - 1, you need to open the door between the rooms with the corresponding key.
// In total the house has several types of doors (represented by uppercase Latin letters) and several types of keys (represented by lowercase Latin letters). The key of type t can open the door of type T if and only if t and T are the same letter, written in different cases. For example, key f can open door F.
// Each of the first n - 1 rooms contains exactly one key of some type that Vitaly can use to get to next rooms. Once the door is open with some key, Vitaly won't get the key from the keyhole but he will immediately run into the next room. In other words, each key can open no more than one door.
// Vitaly realizes that he may end up in some room without the key that opens the door to the next room. Before the start his run for the potato pie Vitaly can buy any number of keys of any type that is guaranteed to get to room n.
// Given the plan of the house, Vitaly wants to know what is the minimum number of keys he needs to buy to surely get to the room n, which has a delicious potato pie. Write a program that will help Vitaly find out this number.

// Input
// The first line of the input contains a positive integer n (2 ≤ n ≤ 105) — the number of rooms in the house.
// The second line of the input contains string s of length 2·n - 2. Let's number the elements of the string from left to right, starting from one.
// The odd positions in the given string s contain lowercase Latin letters — the types of the keys that lie in the corresponding rooms. Thus, each odd position i of the given string s contains a lowercase Latin letter — the type of the key that lies in room number (i + 1) / 2.
// The even positions in the given string contain uppercase Latin letters — the types of doors between the rooms. Thus, each even position i of the given string s contains an uppercase letter — the type of the door that leads from room i / 2 to room i / 2 + 1.

// Output
// Print the only integer — the minimum number of keys that Vitaly needs to buy to surely get from room one to room n.

// Examples
// inputCopy
// 3
// aAbB
// outputCopy
// 0
// inputCopy
// 4
// aBaCaB
// outputCopy
// 3
// inputCopy
// 5
// xYyXzZaZ
// outputCopy
// 2

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


    int n;
    cin>>n;
    string s;
    cin>>s;int f=0;
    map<char,int>m;int c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>=97 && s[i]<=122){
            m[s[i]]++;
        }
        else{
            if(m[s[i]+32]>0){
                m[s[i]+32]--;
            }
            else c++;
        }
    }
    cout<<c<<endl;


    return;


}




signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
        solve();
    
    return 0;
}
