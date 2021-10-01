/*
Program to find the length of Highest Mountain in an input array.
*/

/* Test Case 1
Input: {1,2,3,4,5,6,5,4,3,2,0,1,2,3,2,4}
Output: 11
*/

/* Test Case 1
Input: {1,2,3,4,3,2,0,1,2}
Output: 7
*/

#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int highestMountain(vector<int> arr){
  int large=0;
  int n = arr.size();
  for(int i=1;i<=n-2;){
    if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
      int count=1;
      //iterate back
      int j =i;
      while(arr[j]>arr[j-1] and j>=1){
        count++;
        j--;
      }
      //iterate forward
      while(arr[i]>arr[i+1] and i<=n-2){
        count++;
        i++;
      }
      large = max(count,large);
    }
    
    else{
      i++;
    }
  }
  
  return(large);
}
int main() 
{
  vector<int> arr = {1,2,3,4,3,2,0,1,2};
  cout<<highestMountain(arr);
   
  return 0;
}
