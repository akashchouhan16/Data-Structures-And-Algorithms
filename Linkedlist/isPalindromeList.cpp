#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

typedef struct Node
{
    struct Node *next;
    int data;
} List;

void CreateList(List **head)
{
    List *temp = new List(), *p = *head;
    int ch;
    do
    {
        temp = new List();
        temp->next = NULL;
        cout << "Enter Node Data : ";
        cin >> temp->data;
        if (!(*head))
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
        cout << "Node Created! create another?(1/0) : ";
        cin >> ch;
    } while (ch == 1);
    return;
}
void Display(List *head)
{
    if (head)
    {
        cout << head->data << "->";
        Display(head->next);
    }
    else
    {
        cout << "NULL\n";
        return;
    }
}
bool isPalindrome(List *head)
{
    if (!head)
        return true;
    List *ptr1 = head;
    List *ptr2 = head;
    while (ptr2 && ptr2->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    List *q = NULL, *r = NULL;
    while (ptr1)
    {
        r = q;
        q = ptr1;
        ptr1 = ptr1->next;
        q->next = r;
    }
    ptr2 = q;
    ptr1 = head;
    while (ptr2)
    {
        if (ptr1->data != ptr2->data)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

int main()
{
    List *head = NULL;
    CreateList(&head);
    cout << "Input List : ";
    Display(head);
    if (isPalindrome(head))
        cout << "Yes, List is a Palindromic List\n";
    else
        cout << "No, List is non palindromic\n";
    return 0;
}