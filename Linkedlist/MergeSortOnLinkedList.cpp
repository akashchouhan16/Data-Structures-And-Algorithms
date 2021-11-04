/*Problem Statement : Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort. If the length of linked list is odd, then the extra node should go in the first list while splitting.

Sample Test Case :
2
[*] Any Node Non Negative or Zero Node value is saved as input.
Enter Node Values : 19 17 18 15 14 11 9 6 7 3 5 1 -1
[*] LL Created.
[*] Input List : 19->17->18->15->14->11->9->6->7->3->5->1->NULL
[*] Output List : 1->3->5->6->7->9->11->14->15->17->18->19->NULL

[*] Any Node Non Negative or Zero Node value is saved as input.
Enter Node Values : 3 5 2 4 1 7 12 1 9 -1
[*] LL Created.
[*] Input List : 3->5->2->4->1->7->12->1->9->NULL
[*] Output List : 1->1->2->3->4->5->7->9->12->NULL
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

void findMiddle(ListNode *head, ListNode **first, ListNode **second)
{
    ListNode *slow = head, *fast = head->next;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *first = head;
    *second = slow->next;
    slow->next = nullptr;
    return;
}
ListNode *merge(ListNode *head1, ListNode *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    ListNode *res = nullptr;
    if (head1->_val <= head2->_val)
    {
        res = head1;
        res->next = merge(head1->next, head2);
    }
    else
    {
        res = head2;
        res->next = merge(head1, head2->next);
    }
    return res;
}
void Solve(ListNode **head)
{
    ListNode *curr = *head;
    if (!curr or !curr->next)
        return;

    ListNode *first = nullptr, *second = nullptr;
    findMiddle(curr, &first, &second);
    Solve(&first);
    Solve(&second);

    *head = merge(first, second);
}
ListNode *mergeSort(ListNode *head)
{
    if (!head or !head->next)
        return head;
    Solve(&head);
    return head;
}

signed main()
{
    tests
    {
        ListNode *head = createList();
        cout << "[*] Input List : ";
        display(head);
        head = mergeSort(head);

        cout << "[*] Output List : ";
        display(head);
    }
    return 0;
}