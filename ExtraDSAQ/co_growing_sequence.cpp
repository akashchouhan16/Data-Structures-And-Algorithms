#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD =  1e9+7;
#define rep(i,a,b) for(ll i=a;i<b;++i) 
#define pii pair<int,int>
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        int a[n];
        rep(i,0,n)
        cin>>a[i];
        cout<<"0 ";
        int p=a[0];
        rep(i,1,n)
        {
            int c=0;
            rep(j,0,31)
            {
                int t = (1<<j);
                if(p & t)
                {
                    if(!(a[i]&t))
                    c|=t,a[i]|=t;
                }
            }
            cout<<c<<" ";
            p=a[i];
        }
        cout<<"\n";
    }
}
