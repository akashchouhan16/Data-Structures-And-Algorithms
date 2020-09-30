#include<bits/stdc++.h>
using namespace std;
// Using Hash Map. a different soln.

void findMajority(int *arr, int n) {
    unordered_map<int, int> m;

    for (int i=0;i<n;i++)
        m[arr[i]]++;
    int count = 0;
    for (auto i : m) {
        if (i.second>n/2) {
            count = 1;
            cout<<"Majority Element is "<<i.first<<endl;
            break;
        }
    }
    if (count==0)
        cout<<"No Majority Element present."<<endl;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    findMajority(arr, n);
}
