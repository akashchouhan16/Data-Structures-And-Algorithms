/* Algorithm implementation to calulate how much water is trapped, 
given n non-negative integers representing height of bars and width of each bar is 1 */

/* Sample Test Case 1:
Input Array: {0,1,0,2,1,1,1,4,2,1,2,1}
Output: 5
*/
/* Sample Test Case 2:
Input Array: {3, 0, 2, 0, 4 }
Output: 7
*/
//Complexity O(N)

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
int rainWaterHarvest(vector<int> arr){
  int n = arr.size();
  
  if(n<=2){
    return(0);
  }
  else{
    
    vector<int> left(n,0);
    vector<int> right(n,0);
    
    int sum=0;
    
    left[0]=arr[0];
    right[n-1]=arr[n-1];
  
    int i=1;
    while(i<n){
      left[i]=max(left[i-1],arr[i]);
      i++;
    }
    
    i=n-2;
    while(i>=0){
      right[i]=max(right[i+1],arr[i]);
      i--;
    }
    
    for(i=0;i<n;i++){
      sum+=(min(left[i],right[i])-arr[i]);
    }
    return(sum);  
  }
  
}

int main() 
{
  vector<int> arr = {3, 0, 2, 0, 4 };
  cout<<rainWaterHarvest(arr);
  return 0;
}


