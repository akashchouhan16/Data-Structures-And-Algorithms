// Recursive way to solve Interleaving Strings
// We are given three strings say a,b and c. We should check whether third string(c) is formed by interleaving first(a) and second(b) strings.
// If a string is formed by interleaving 2 strings, it means the string has all the characters of first and second strings and also their order is preserved

//test-case1 : A="aab", B= "bcb", C = "ababcb" output: C is a interleaved string
//test-case2 : A="aab", B = "bcb", C= "bbaacb" output: C is not interleaved string

#include<iostream>
#include<string>
using namespace std;

bool InterleavingString(string A,string B,string C,int i,int j,int k) //i indicates ith character of C ,j -> jth character of A, k-> kth character of B
{
    if(i != -1 && C.length() != B.length()+A.length()) 
        return false;
    if(i==-1 && j == -1 && k == -1)
        return true;
    if(C[i] == A[j] && A[j] != B[k])                //A[j] matched with C[i]
        return InterleavingString(A,B,C,i-1,j-1,k);
    if(C[i] == B[k] && A[j] != B[k])                //B[k] matched with C[i]
        return InterleavingString(A,B,C,i-1,j,k-1);
    if(C[i] == A[j] && A[j] == B[k])                //A[j] = B[k] = C[i], hence we should consider 2 cases, 1.assuming ith character of C is from jth of A ,2. assuming ith character of C is from kth character of B.
        return InterleavingString(A,B,C,i-1,j-1,k) || InterleavingString(A,B,C,i-1,j,k-1);
    else                                            //C[i] didnt match with A[j] and B[k] 
        return false;
}

int main()
{
    string A,B,C;
    cin>>A>>B>>C;
    if(InterleavingString(A,B,C,5,2,2) == 0)
       cout<< "C is not interleaved string";
    else
       cout<<"C is a interleaved string";
    return 0;

}