#include <bits/stdc++.h>
#include <algorithm>

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
// Solution -> Time O(nlogK), Space O(K)
ListNode *Solve(ListNode *head, int K)
{
    if (not head)
        return head;
    ListNode *p = head;
    priority_queue<ListNode *, vector<ListNode *>, greater<ListNode *>> PQ;

    for (int i = 0; i <= K and p; i++)
    {
        PQ.push(p);
        p = p->next;
    }
    ListNode *header = nullptr;
    ListNode *ptr = header;
    while (not PQ.empty())
    {
        if (header == nullptr)
        {
            header = PQ.top();
            header->prev = nullptr;
            ptr = header;
        }
        else
        {
            ptr->next = PQ.top();
            PQ.top()->prev = ptr;
            ptr = PQ.top();
        }
        PQ.pop();

        if (p)
        {
            PQ.push(p);
            p = p->next;
        }
    }
    ptr->next = nullptr;
    return header;
}

signed main()
{
    ListNode *head = nullptr;
    tests
    {
        head = createDoublyList();
        int K = 0;
        cin >> K;
        head = Solve(head, K);
        cout << "[*] Output: ";
        display(head);
    }
    return 0;
}