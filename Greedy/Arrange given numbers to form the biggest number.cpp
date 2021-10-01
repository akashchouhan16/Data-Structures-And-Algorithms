/*
Problem statement:
Given an array of numbers, arrange them in a way that yields the largest value. 

Example Testcases:
If the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value. 
If the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int myCompare(string X, string Y)
{
	string XY = X.append(Y);
	string YX = Y.append(X);
	return XY.compare(YX) > 0 ? 1 : 0;
}

void printLargest(vector<string> arr)
{
	sort(arr.begin(), arr.end(), myCompare);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
}

// Driver code
int main()
{
	vector<string> arr;
	arr.push_back("54");
	arr.push_back("546");
	arr.push_back("548");
	arr.push_back("60");
	printLargest(arr);

	return 0;
}
