#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} DoublyList;

void CreateList(DoublyList **head)
{
    DoublyList *temp = NULL, *tail = *head;
    int ch;
    do
    {
        temp = new DoublyList();
        temp->next = temp->prev = NULL;
        srand(time(NULL));
        temp->data = 1 + rand() % 10;
        if (!(*head))
        {
            *head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        cout << "Node Created!\n Create Another?(1/0) : ";
        cin >> ch;
    } while (ch == 1);
    cout << "List Created!\n";
    return;
}
void Display(DoublyList *head)
{
    if (head)
    {
        cout << head->data << " <=> ";
        Display(head->next);
    }
    else
    {
        cout << "NULL\n";
        return;
    }
}
void RotateRight(DoublyList **head, int shifts)
{
    DoublyList *temp, *ptr = *head;
    int shift = shifts;
    if (!ptr)
        return;
    while (shifts--)
    {
        ptr = *head;
        while (ptr->next)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        ptr->prev = NULL;
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
    }
    cout << "Rotated Left by " << shift << " Nodes\n";

    return;
}
void RotateLeft(DoublyList **head, int shifts)
{
    DoublyList *temp = NULL, *ptr = *head;
    int shift = shifts;
    if (!ptr)
        return;
    while (shifts--)
    {
        ptr = *head;
        temp = *head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        temp->next = NULL;
        ptr->next = temp;
        temp->prev = ptr;
    }
    cout << "Rotated Right by " << shift << " Nodes.\n";
    return;
}

int main()
{
    DoublyList *head = NULL;
    CreateList(&head);
    cout << "Input List : ";
    Display(head);
    int ch, shifts = 1;
    cout << "Enter -1 to Rotate Right | Enter 1 to Rotate Left | Enter 0 to exit()\n";
    do
    {
        cout << "Enter Choice : ";
        cin >> ch;
        if (ch == -1)
        {
            cout << "Enter Shifts : ";
            cin >> shifts;
            RotateRight(&head, shifts);
            cout << "\nNew List : ";
            Display(head);
        }
        else if (ch == 1)
        {
            cout << "Enter Shifts : ";
            cin >> shifts;
            RotateLeft(&head, shifts);
            cout << "New List : ";
            Display(head);
        }
        else
            break;
    } while (ch != 0);
    free(head);
    return 0;
}