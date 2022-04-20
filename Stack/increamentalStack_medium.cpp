/* Problem Statement: To Implement a class Stack which would contain the following methods:
    1. push(element)
    2. pop(void)
    3. peep()
    4. increment(int index, int value)
    > Primary methods have the classical implementation of a stack ADT.
    > The increment(int,int) will take the bottom i elements into consideration and will inc them by `value`.
Sample Test Case:
Written in main().
OUTPUT:
-1
8
*/
#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define all(x) x.begin(), x.end()
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

class Stack
{
    vector<int> stackArray;
    vector<int> IncrementArray;

public:
    Stack() {}
    void push(int element);               // O(1)
    int pop();                            // O(1)
    int peek();                           // O(1)
    void increment(int index, int value); // O(1)
};

// Method Definitions:
void Stack::push(int element)
{
    stackArray.push_back(element);
    IncrementArray.push_back(0);
    return;
}

int Stack::pop()
{
    if (not stackArray.size())
        return -1;

    int size = IncrementArray.size();
    int lastIncrementalValue = IncrementArray[size - 1];
    IncrementArray.pop_back();
    size = IncrementArray.size();
    if (size > 0)
        IncrementArray[size - 1] += lastIncrementalValue;

    int element = stackArray.back();
    stackArray.pop_back();

    return element + lastIncrementalValue;
}

int Stack::peek()
{
    if (stackArray.size())
        return stackArray.back() + IncrementArray.back();
    return -1;
}
void Stack::increment(int index, int value)
{
    // mentioned in the problem statement that the index will always be valid. No corner checks needed here.
    IncrementArray[index - 1] += value;
    return;
}

signed main()
{

    Stack St;
    St.push(1);
    St.pop();
    cout << St.peek() << endl;
    St.push(3);
    St.push(5);
    St.push(2);
    St.increment(1, 5);
    St.pop();
    St.pop();
    cout << St.peek() << endl;

    return 0;
}