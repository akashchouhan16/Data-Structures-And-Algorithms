#ifndef Utility
#define Utility
#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int d)
    {
        data = d;
    }
} ListNode;

int CountNode(ListNode *p)
{
    if (!p)
    {
        return 0;
    }
    else
        return CountNode(p->next) + 1;
}

int CountEven(ListNode *p)
{
    int counter = 0;
    while (p)
    {
        if (p->data % 2 == 0)
            counter++;
        p = p->next;
    }
    return counter;
}
int visited = 0;
void ReverseDisplayDLL(ListNode *p)
{
    if (p)
    {
        ReverseDisplayDLL(p->next);
        if (!p->prev && !visited)
        {
            visited = 1; //mutex.
            cout << p->data;
            return;
        }
        cout << p->data << "<->";
    }
    else
    {
        cout << "NULL<->";
        return;
    }
}

#endif