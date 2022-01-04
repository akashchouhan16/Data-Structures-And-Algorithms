/*Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
The amount of petrol that every petrol pump has distance from that petrol pump to the next petrol pump.
Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n). Assume for 1-litre petrol, the truck can go 1 unit of distance.
Sample test case: 
  Input: {4, 6}, {6, 5}, {7, 3} and {4, 5}.
 Output: 2

*/
#include<iostream>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
	cout<<"a";
	int i=0;
	int balance=0;
	int c=0,start=0;
	do
	{
	 ++c;
	 balance+=p[i].petrol-p[i].distance;
	  cout<<"b"<<i<<balance<<endl;
	  if(balance<0)
	  {
	  	start=i+1;
	  	balance=0;
	  }
	  if(i==n-1)
	   i=0;
	  else
	   ++i;
	}while(i!=start&&c!=2*n);
  if(start==0&&i==0)
   return 0;
  else if(balance+p[i+1].petrol-p[i+1].distance>=0)
	return start;
   else
     return -1;
}
int main()
{
    int n;
    cin>>n;
    petrolPump p[n];
    for(int i=0;i<n;i++)
    {
	 cout<<"c-"<<i<<endl;
	 cin>>p[i].distance>>p[i].petrol;
    }
    cout<<tour(p,n)<<endl;
    }

