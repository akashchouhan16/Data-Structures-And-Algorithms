// Given a array and list of ranges. we are supposed to find minimum element from the range.
//Test case1: arr = {1,3,4,8,6,1,4,2}, range = [1,3] output: 3
//Test case1: arr = {1,3,4,8,6,1,4,2}, range = [2,5] output: 1
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

void RangeMin(vector<int> arr, vector<pair<int,int>> queries)
{
    vector<vector<int>> SparseTable(arr.size());
    for(int i = 0; i < arr.size();i++)
       SparseTable[i].push_back(arr[i]);
    for(int j = 1; j < log2(arr.size())+1; j++)
    {
        for(int i = 0; i+(1<<(j)) < arr.size()+1; i++ )
           SparseTable[i].push_back(min(SparseTable[i][j-1], SparseTable[i+(1<<(j-1))][j-1]));
    }
    for(int i = 0; i < queries.size(); i++)
    {
        int l = queries[i].first;
        int r = queries[i].second;
        int LeastPowerOf2 = log2(r-l+1);
        cout<<min(SparseTable[l][LeastPowerOf2],SparseTable[r-(1<<LeastPowerOf2)+1][LeastPowerOf2])<<endl;
    }
}

int main()
{
    vector<int> arr{1,3,4,8,6,1,4,2};
    vector<pair<int,int>> queries;
    queries.push_back(make_pair(1,3));
    queries.push_back(make_pair(2,5));
    queries.push_back(make_pair(0,4));
    queries.push_back(make_pair(2,6));
    queries.push_back(make_pair(6,7));
    RangeMin(arr,queries);
    return 0;
}