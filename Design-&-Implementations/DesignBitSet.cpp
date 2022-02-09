/*
Problem Statement: A Bitset is a data structure that compactly stores bits.

Sample Test Case:
["Bitset","fix","fix","flip","all","unfix","flip","one","unfix","count","toString"]
[[5],[3],[1],[],[],[0],[],[],[0],[],[]]
OUTPUT:
NOT ALL BITS SET, AT LEAST ONE BIT IS SET, Bit COUNT(1): 2, String bitset: 01010,
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define nullptr NULL
#define ff first
#define ss second
#define ll long long
#define lb long double
#define g(x) greater<x>
#define loop(i, n) for (int i = 0; i < n; i++)

#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

class BitSet
{
    string bitStream, bitStream_inverse;
    int setBitCount;
    bool isFlipped;

public:
    BitSet(int size = 0)
    {
        bitStream = string(size, '0');
        bitStream_inverse = string(size, '1');
        isFlipped = false;
        setBitCount = 0;
    }
    // Design APIs in O(1) Time.
    bool all();         // Check if all the bits in the stream are SET. [i.e., '1']
    bool one();         // check if at least 1 bit in the stream is SET.
    void fixBit(int);   // Make idx bit to 1.
    void unfixBit(int); // Make idx bit to 0.
    void flipBit();     // Invert[0 to 1 && 1 to 0] all the bits in the stream.
    int count();        // Return the set bit count in the current Bitset.
    string toString();  // Returns the current composition of the Bitset as a string.
};

// Definitions:
inline bool BitSet::all()
{
    return this->setBitCount == this->bitStream.size();
}
inline int BitSet::count()
{
    return this->setBitCount;
}
inline bool BitSet::one()
{
    return (setBitCount != 0);
}

inline void BitSet::fixBit(int index)
{
    setBitCount += (bitStream[index] == (isFlipped ? '1' : '0'));
    bitStream[index] = isFlipped ? '0' : '1';
    bitStream_inverse[index] = isFlipped ? '1' : '0';
}

inline void BitSet::unfixBit(int index)
{
    setBitCount -= (bitStream[index] == (isFlipped ? '0' : '1'));
    bitStream[index] = isFlipped ? '1' : '0';
    bitStream_inverse[index] = isFlipped ? '0' : '1';
}
inline void BitSet::flipBit()
{
    isFlipped = not isFlipped;
    setBitCount = bitStream.size() - setBitCount;
}
inline string BitSet::toString()
{
    return (not isFlipped) ? bitStream : bitStream_inverse;
}

// Main:
signed main()
{

    int N;
    cin >> N;
    BitSet object(N);
    object.fixBit(3);
    object.fixBit(1);
    object.flipBit();
    cout << (object.all() ? "ALL BITS SET" : "NOT ALL BITS SET") << ", ";
    object.unfixBit(0);
    object.flipBit();
    cout << (object.one() ? "AT LEAST ONE BIT IS SET" : "NO SET BITS") << ", ";
    object.unfixBit(0);
    cout << "Bit COUNT(1): " << object.count() << ", ";
    cout << "String bitset: " << object.toString() << ", ";
    return 0;
}