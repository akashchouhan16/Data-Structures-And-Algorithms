/*
Program to find the length of longest band of consecutive numbers in any input array.
*/
/* Test Case 1
Input: {1,9,3,0,18,5,2,4,10,7,12,6}
Output: 8
*/

/* Test Case 1
Input: {1,9,3,0,18,5,4,10,7,12,6}
Output: 5
*/

#include <iostream>
#include<vector>
#include<unordered_set>

using namespace std;
int largestBand(vector<int> arr){
  
  int n = arr.size();
  unordered_set<int> s;
  for(int i:arr){
    s.insert(i);
  }
  int large = 0;
  for(auto element: s){
    if(s.find(element-1)==s.end()){
      //start new chain
      int count=1;
      int next = element+1;
      while(s.find(next)!=s.end()){
        count++;
        next++;
      }
      if(count>large){
        large=count;
      }
    }
  }
  return(large);
}

int main() 
{
  
  vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    
  cout<<largestBand(arr);
  
    
  return 0;
}
