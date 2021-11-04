/*Problem Statement: Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value Target.

Sample Test Case:
4
1 2 4 5 7 -1 6
3 5 7 9 14 16 19 20 -1 14
112 141 150 167 169 200 211 216 219 247 249 250 281 289 400 -1 400
1 5 7 9 17 19 21 27 -1 19

Case #1: [4 2]
Case #2: [9 5]
Case #3: [250 150]
Case #4: [-1 -1]
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

#define MOD 1e9 + 7
#define nullptr NULL
#define INF INT_MAX
#define all(x) x.begin(), x.end()
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define mp() make_pair()
#define pb(x) push_back(x)
#define pp() pop_back()
#define loop(i, n) for (int i = 0; i < n; i++)
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

class ListNode
{
public:
    int _val;
    ListNode *next;
    ListNode *prev;
    ListNode(int _val = 0) : _val(_val)
    {
        next = nullptr;
        prev = nullptr;
    }
};
using namespace std;

ListNode *createDoublyList()
{
    int _val;
    ListNode *header = new ListNode(-1);
    ListNode *ptr = header;
    // cout << "[*] Enter Node Vals: ";
    do
    {
        cin >> _val;
        if (_val <= 0)
            break;

        ListNode *newNode = new ListNode(_val);
        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = ptr->next;
    } while (true);

    return header->next;
}
void display(ListNode *head)
{
    while (head)
    {
        cout << head->_val << "<=>";
        head = head->next;
    }
    cout << "NULL\n";
    return;
}
// Brute Force Solution : Time(N), Space O(N)
p(int, int) Solve(ListNode *head, int Target)
{
    if (!head or !head)
        return {-1, -1};
    ListNode *p = head, *q = head;
    unordered_map<int, ListNode *> mp;
    while (p and p->next)
    {
        int difference = Target - p->_val;
        if (mp.find(difference) != mp.end())
        {
            return {p->_val, difference};
        }
        mp[p->_val] = p;
        p = p->next;
    }
    return {-1, -1};
}
signed main()
{
    ListNode *head = nullptr;
    v(p(int, int)) out;
    tests
    {
        head = createDoublyList(); // DLL is Sorted acc to question.
        int target = 0;
        cin >> target;
        out.pb(Solve(head, target));
    }

    loop(i, out.size()) cout << "Case #" << i + 1 << ": [" << out[i].first << " " << out[i].second << "]" << endl;
    return 0;
}