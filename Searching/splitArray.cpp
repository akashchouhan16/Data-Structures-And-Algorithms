/* Problem Statement : Given an integer array nums and an integer k, 
split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
Note - A subarray is a contiguous part of the array.*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int splitArray(vector<int>& nums, int k) {
    int l = 0, r = 0, n = nums.size();
    for (int i = 0; i < n; ++i) l = max(l, nums[i]), r += nums[i];

    int mid = 0, ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        int count = 0, tempsum = 0;
        for (int i = 0; i < n; ++i) {
            if (tempsum + nums[i] <= mid) tempsum += nums[i];
            else count++, tempsum = nums[i];
        }
        count++;

        if (count <= k) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int k;
    cin >> k;

    cout << splitArray(vec, k) << endl;
    return 0;
}
