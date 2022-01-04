/*Problem Statement:

Sample Test Case:
2
[*] Enter Node Vals: 1 3 5 7 8 11 -1
[*] Enter Target: 9
[*] Enter Node Vals: 1 2 4 5 6 8 9 -1
[*] Enter Target: 15
Case #1: 1
Case #2: 5
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define nullptr NULL
#define INF INT_MAX

#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define pb(x) push_back(x)
#define pp() pop_back()
#define all(X) X.begin(), X.end()
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
    cout << "[*] Enter Node Vals: ";
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

int countTriplets(ListNode *head, int Target)
{
    if (!head or !head->next or !Target)
        return 0;
    int count = 0;
    ListNode *p = head, *tail = head;
    while (tail and tail->next)
        tail = tail->next;

    while (p and p->next)
    {
        ListNode *low = p->next, *high = tail;

        int newTarget = (Target - p->_val);
        while (low and high and low != high and high->next != low)
        {
            int currSum = low->_val + high->_val;
            if (currSum == newTarget)
            {
                count++;
                low = low->next;
                high = high->prev;
            }
            else if (currSum > newTarget)
                high = high->prev;
            else
                low = low->next;
        }
        p = p->next;
    }
    return count;
}
bool isDLLSorted(ListNode *head)
{
    if (!head or !head->next)
        return true;

    ListNode *p = head->next;
    while (p)
    {
        if (p->_val < p->prev->_val)
            return false;

        p = p->next;
    }
    return true;
}
void deleteDLL(ListNode **head)
{
    ListNode *temp = nullptr;
    int nodeCount = 0, byteCount = int(sizeof(*head));
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        delete temp;
        nodeCount++;
    }
    byteCount *= nodeCount;
    // For Test:
    // cout << "[*] Deleted DLL. " << byteCount << "bytes Freed.\n";
    return;
}
signed main()
{
    v(int) out;
    ListNode *head = nullptr;
    tests
    {
        int target = 0;
        head = createDoublyList();
        // Check #1
        if (not isDLLSorted(head))
        {
            cout << "[*] Invalid Input\n";
            exit(1);
        }
        // For Test
        // cout << "[*] Input List: ";
        // display(head);
        cout << "[*] Enter Target: ";
        cin >> target;
        out.pb(countTriplets(head, target));
        deleteDLL(&head);
    }

    loop(i, out.size()) cout << "Case #" << i + 1 << ": " << out[i] << endl;
    return 0;
}