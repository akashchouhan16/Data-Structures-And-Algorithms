/* Problem Statement : Given an integer array nums, 
return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
--> 0 <= i < j < nums.length and
--> nums[i] > 2 * nums[j]. */


#include<bits/stdc++.h>
using namespace std;

 int reversePairs(vector < int > & arr) {
      int Pairs = 0;
      for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
          if (arr[i] > 2 * arr[j]) Pairs++;
        }
      }
      return Pairs;
    }


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    cout<<reversePairs(arr)<<endl;
    return 0;
}
