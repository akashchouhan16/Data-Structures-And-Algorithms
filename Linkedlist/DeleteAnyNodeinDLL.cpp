#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} DoublyList;

void CreateList(DoublyList **head)
{
    DoublyList *temp = NULL, *ptr = *head;
    int ch;
    cout << "Enter 1 to Insert Node\nEnter 0 to Terminate.\n";
    do
    {
        cout << "Enter Choice :(1/0) ";
        cin >> ch;
        if (ch == 1)
        {
            temp = new DoublyList();
            temp->next = temp->prev = NULL;
            srand(time(NULL));
            temp->data = (1 + rand() % 20);
            if (!(*head))
            {
                *head = ptr = temp;
            }
            else
            {
                ptr->next = temp;
                temp->prev = ptr;
                ptr = temp;
            }
            cout << "New Node Created!\n";
        }
        else if (ch == 0)
            break;
    } while (ch != 0);
    cout << "Doubly Linked List Created!\n";
    return;
}
void Display(DoublyList *head)
{
    if (head)
    {
        cout << head->data << "<=>";
        Display(head->next);
    }
    else
    {
        cout << "NULL\n";
        return;
    }
}
int CountNodes(DoublyList *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
DoublyList *DeleteAtAnyPosition(DoublyList **head, int position)
{
    DoublyList *temp = *head;
    if (!temp)
    {
        cout << "List if Empty! Nothing to delete\n";
        return NULL;
    }
    if (position < 0 || position > CountNodes(*head))
    {
        cout << "Invalid Position!\n";
        return NULL;
    }
    else
    {
        for (int i = 0; i < position - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (temp == *head)
        {
            (*head) = (*head)->next;
            (*head)->prev = NULL;
            DoublyList *deleted = temp;
            free(temp);
            return deleted;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            DoublyList *deleted = temp;
            free(temp);
            return deleted;
        }
    }
    return NULL;
}
int main()
{
    int pos = 0;
    DoublyList *head = NULL;
    CreateList(&head);
    cout << endl
         << "List : ";
    Display(head);
    cout << "Enter Position to Delete (Enter -1 to Terminate Deletion) : ";
    do
    {
        cout << "Enter position : ";
        cin >> pos;
        if (pos == -1)
            break;
        DeleteAtAnyPosition(&head, pos);
        cout << "Node Deleted!\n Node Count : ";
        cout << CountNodes(head) << endl;
        Display(head);
    } while (pos != -1);
    cout << "terminated!\n";
    free(head);
    return 0;
}