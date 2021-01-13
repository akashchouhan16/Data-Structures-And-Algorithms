#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
} DoubleList;

void CreateList(DoubleList **head)
{
    DoubleList *temp = NULL, *p = *head;
    int ch;
    do
    {
        temp = new DoubleList();
        temp->next = temp->prev = NULL;
        srand(time(NULL));
        temp->data = 1 + rand() % 15;
        if (!(*head))
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            temp->prev = p;
            p = temp;
        }
        cout << "Node Created! Create another?(1/0) : ";
        cin >> ch;
    } while (ch == 1);
    cout << "Doubly List Created!\n";
    return;
}
void Display(DoubleList *head)
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
void DeleteLastOccurrence(DoubleList **head, int data)
{
    DoubleList *targetNode = *head, *tail = *head;
    while (tail != NULL)
    {
        if (tail->data == data)
        {
            targetNode = tail;
        }
        tail = tail->next;
    }
    if (targetNode == *head)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
        cout << "Node wil Data " << targetNode->data << " deleted.\n";
        free(targetNode);
        return;
    }
    targetNode->prev->next = targetNode->next;
    if (targetNode->next)
        targetNode->next->prev = targetNode->prev;
    else
        targetNode->prev->next = NULL;
    cout << "Node wil Data " << targetNode->data << " deleted.\n";
    free(targetNode);
    return;
}

int main()
{
    int data;
    DoubleList *head = NULL;
    CreateList(&head);
    cout << "Input List : ";
    Display(head);
    cout << "Choose Node to Delete : ";
    cin >> data;
    DeleteLastOccurrence(&head, data);
    cout << "New List : ";
    Display(head);
    free(head);
    return 0;
}