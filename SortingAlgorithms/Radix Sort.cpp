//Radix Sort

/* The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort uses 
counting sort as a subroutine to sort. Elements in the range from 1 to n^2. 
The time complexity of radix sort is given by the formula,T(n) = O(d*(n+b)), where d is the number of digits in the given list, 
n is the number of elements in the list, and b is the base or bucket size used, which is normally base 10 for decimal representation.*/

// C++ implementation of Radix Sort
#include <iostream>
using namespace std;


int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{
	int output[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	int m = getMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int n;
    cout<<"Enter number of Elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        {cin>>arr[i];}
	
	radixsort(arr, n);
	print(arr, n);
	return 0;
}

//Input 1:
//170, 45, 75, 90, 802, 24, 2, 66

//OUTPUT 1:
//2 24 45 66 75 90 170 802

//Input 2:
//2, 24, 12, 98, 66, 0, 405, 3555, 43, 10

//OUTPUT 2:
//0 2 10 12 24 43 66 98 405 3555