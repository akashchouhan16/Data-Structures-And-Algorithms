#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef struct Node
{
    struct Node *next;
    int data;
} LinkedList;

void CreateList(LinkedList **head)
{
    LinkedList *temp, *tail = *head;
    int ch;
    do
    {
        temp = new LinkedList();
        temp->next = nullptr;
        temp->data = 1 + rand() % 34;
        if (!(*head))
        {
            *head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        cout << "Node Created! Create Another?(1/0) : ";
        cin >> ch;
    } while (ch == 1);
    return;
}

void Display(LinkedList *head)
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
void DeleteNthfromEnd(LinkedList **head, int n)
{
    if (!head)
        return;
    LinkedList *p = *head;
    LinkedList *q = *head;
    while (q->next)
    {
        if (n > 0)
        {
            q = q->next;
            n--;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    if (n == 0)
        p->next = p->next->next;
    else
        *head = (*head)->next;
    return;
}

int main()
{
    LinkedList *head = NULL;
    CreateList(&head);
    cout << "Input List : ";
    Display(head);
    int n;
    cout << "Enter N : ";
    cin >> n;
    DeleteNthfromEnd(&head, n);
    cout << "New List : ";
    Display(head);
    free(head);
    return 0;
}