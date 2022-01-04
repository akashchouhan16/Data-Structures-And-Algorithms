/*Problem Statement:Given a singly linked list, remove all the nodes which have a greater value on its following nodes.
Sample Test Case:
3
[*] Any Node Non Negative or Zero Node value is saved as input.
Enter Node Values : 12 15 10 11 5 6 2 3 -1
[*] LL Created.
[*] Input List : 12->15->10->11->5->6->2->3->NULL
[*] Output List : 15->11->6->3->NULL
[*] Any Node Non Negative or Zero Node value is saved as input.
Enter Node Values : 10 20 30 40 50 60 -1
[*] LL Created.
[*] Input List : 10->20->30->40->50->60->NULL
[*] Output List : 60->NULL
[*] Any Node Non Negative or Zero Node value is saved as input.
Enter Node Values : 19 5 1 5 6 -1
[*] LL Created.
[*] Input List : 19->5->1->5->6->NULL
[*] Output List : 19->6->NUL
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

#define nullptr NULL
#define INF INT_MAX
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
    ListNode(int _val = 0) : _val(_val), next(nullptr) {}
};

ListNode *createList()
{
    int _val;
    ListNode *header = new ListNode(-1);
    ListNode *p = header;
    cout << "[*] Any Node Non Negative or Zero Node value is saved as input.\nEnter Node Values : ";
    do
    {

        cin >> _val;
        if (_val <= 0)
            break;

        ListNode *newNode = new ListNode(_val);
        p->next = newNode;
        p = p->next;
    } while (true);
    cout << "[*] LL Created.\n";
    return header->next;
}
void display(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        cout << p->_val << "->";
        p = p->next;
    }
    cout << "NULL\n";
    return;
}
ListNode *reverseList(ListNode *head)
{
    if ((!head) or (!head->next))
        return head;
    ListNode *rear = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return rear;
}
ListNode *Solve(ListNode *head)
{
    if (not head)
        return head;
    // 12-15->10->11->5->6->2->3  OUT: [15,11,6,3]

    head = reverseList(head);
    int MAX = head->_val;
    ListNode *p = head, *q = head;
    p = p->next;
    while (p)
    {
        if (p->_val < MAX)
        {
            q->next = p->next;
            p = q->next;
        }
        else
        {
            q = p;
            MAX = p->_val;
            p = p->next;
        }
    }
    head = reverseList(head);
    return head;
}

signed main()
{
    tests
    {
        ListNode *head = createList();
        cout << "[*] Input List : ";
        display(head);

        head = Solve(head);
        cout << "[*] Output List : ";
        display(head);
    }
    return 0;
}