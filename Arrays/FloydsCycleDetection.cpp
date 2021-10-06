// Given an array of size n+1, all the elements are in range of [1,n].It is guaranteed that all the elements appear either once or may not appear at all, but there exists one element that appears more than once.

#include<iostream>
#include<vector>
using namespace std;
int FindDuplicate(vector<int> array)
{
    int tortoise = array[0];            //slow-pointer
    int hare = array[0];                //fast-pointer

    
    do {
        tortoise = array[tortoise];
        hare = array[array[hare]];
    } while (tortoise != hare);         //Finding intersection point

    // Find the "entrance" to the cycle.
    tortoise = array[0];
    while (tortoise != hare) {
        tortoise = array[tortoise];
        hare = array[hare];
    }

    return hare;
}
int main()
{
    vector<int> array{5,4,1,2,2,3};
    cout << FindDuplicate(array);

    return 0;
}
