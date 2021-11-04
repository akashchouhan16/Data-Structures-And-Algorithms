/*Problem Statement : To cLone a LinkedList with next and random pointer
Sample Tests :
[*] Enter Node Val : 1
[*] Enter Node Val : 2
[*] Enter Node Val : 3
[*] Enter Node Val : 4
[*] Enter Node Val : 5
[*] Enter Node Val : 0
[*] LL Created.
[*] Update Random Ptr
To update a random Ptr : 1
Exit : 0[*] Enter choice : 1
[*] Enter SRC and DEST Node Val : 1 3
[*] Enter choice : 1
[*] Enter SRC and DEST Node Val : 2 1
[*] Enter choice : 1
[*] Enter SRC and DEST Node Val : 3 5
[*] Enter choice : 1
[*] Enter SRC and DEST Node Val : 4 5
[*] Enter choice : 1
[*] Enter SRC and DEST Node Val : 5 2
[*] Enter choice : 0
[*] Input List : [1 | 0x156c20 | 0x151360]->[2 | 0x151360 | 0x156c00]->[3 | 0x151380 | 0x1513a0]->[4 | 0x1513a0 | 0x1513a0]->[5 | 0 | 0x156c20]->NULL
[*]Copied List : [1 | 0x1513e0 | 0x151400]->[2 | 0x151400 | 0x1513c0]->[3 | 0x151420 | 0x151440]->[4 | 0x151440 | 0x151440]->[5 | 0 | 0x1513e0]->NULL
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
    ListNode *random;
    ListNode(int _val = 0) : _val(_val)
    {
        next = nullptr;
        random = nullptr;
    }
};

ListNode *createList()
{
    int _val;
    ListNode *header = new ListNode(-1);
    ListNode *p = header;
    do
    {
        cout << "[*] Enter Node Val : ";
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
ListNode *updateRandomPtr(ListNode *head)
{
    if (!head)
        return head;
    int node_src, node_dest, ch = 1;
    cout << "[*] Update Random Ptr\nTo update a random Ptr : 1\nExit : 0";
    while (ch == 1)
    {
        cout << "[*] Enter choice : ";
        cin >> ch;
        if (ch != 1)
            break;

        cout << "[*] Enter SRC and DEST Node Val : ";
        cin >> node_src >> node_dest;
        ListNode *p_src = head, *p_dest = head;
        while (p_src and p_src->_val != node_src)
            p_src = p_src->next;
        while (p_dest and p_dest->_val != node_dest)
            p_dest = p_dest->next;

        if (p_dest and p_src)
            p_src->random = p_dest;
    }
    return head;
}
void display(ListNode *head)
{
    if (head)
    {
        cout << "[" << head->_val << " | " << head->next << " | " << head->random << "]->";
        display(head->next);
    }
    return;
}
bool deleteList(ListNode **head)
{
    if (head)
    {
        ListNode *temp = *head;
        (*head) = (*head)->next;
        delete temp;
    }
}

ListNode *cloneLinkedList(ListNode *head)
{
    if (!head)
        return head;

    ListNode *curr = head, *temp = nullptr;
    while (curr)
    {
        temp = curr->next;
        curr->next = new ListNode(curr->_val);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;
    while (curr)
    {
        curr->next->random = (curr->random) ? curr->random->next : nullptr;
        curr = curr->next->next;
    }
    ListNode *original = head, *copyHead = head->next;
    ListNode *resultant = copyHead;
    while (original)
    {
        original->next = original->next->next;
        copyHead->next = (copyHead->next) ? copyHead->next->next : nullptr;
        original = original->next;
        copyHead = copyHead->next;
    }
    return resultant;
}
signed main()
{
    ListNode *head = createList();
    head = updateRandomPtr(head);
    cout << "[*] Input List : ";
    display(head);
    cout << "NULL\n";

    ListNode *CopyHead = cloneLinkedList(head);
    deleteList(&head);
    cout << "[*] Copied List : ";
    display(CopyHead);
    cout << "NULL\n";
    deleteList(&CopyHead);
    return 0;
}