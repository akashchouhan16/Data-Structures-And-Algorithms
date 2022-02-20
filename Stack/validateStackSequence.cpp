/*
Sample Test Cases:
3
5
1 2 3 4 5
4 5 3 2 1
5
1 2 3 4 5
4 3 5 1 2
4
1 4 6 8
8 4 6 1
OUTPUT:
VALID Stack Sequence
INVALID Stack Sequence
INVALID Stack Sequence
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

class Solution
{
    vector<int> pushed, popped;
    int size;

public:
    Solution(int _size) : size(_size)
    {
        pushed.resize(size);
        popped.resize(size);
    }
    void input()
    {
        int element = -1, i = 0;
        while (i < size)
        {
            cin >> element;
            pushed[i++] = element;
        }
        i = 0;
        while (i < size)
        {
            cin >> element;
            popped[i++] = element;
        }
    }
    // Approach I: O(N) Time and O(N) space, using an actual Stack.
    bool isValidStackSequence_I()
    {
        stack<int> St;
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            St.push(pushed[i]);
            while (not St.empty() and St.top() == popped[j])
            {
                St.pop();
                j++;
            }
        }
        return St.empty();
    }
    // Approach II: Using O(N) Time and O(1) space. Using two pointers to emulate a stack.
    bool isValidStackSequence_II()
    {
        int push_index = -1, pop_index = 0;

        for (int i = 0; i < size; i++)
        {
            pushed[++push_index] = pushed[i];
            while (push_index >= 0 and pushed[push_index] == popped[pop_index])
            {
                ++pop_index;
                --push_index;
            }
        }
        return push_index == -1;
    }
};

signed main()
{
    tests
    {
        int N;
        cin >> N;
        Solution object(N);
        object.input();

        cout << (object.isValidStackSequence_II() ? "VALID Stack Sequence" : "INVALID Stack Sequence");
        cout << endl;
    }
}