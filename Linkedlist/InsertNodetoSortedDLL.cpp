/*
    Author : Akash Chouhan
    github : github.com/akashchouhan16/
    mail : akash.c1500@gmail.com
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#define pb push_back
#define pob pop_back

using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
} LinkedList;

LinkedList *CreateList(LinkedList *head)
{
    LinkedList *temp = NULL, *p = head;
    int n1, n2, ch = 0;
    cout << "Enter the Element Range : ";
    cin >> n1 >> n2;
    srand(time(nullptr));
    do
    {
        temp = new LinkedList(n1 + rand() % (n2 - n1 + 1));
        if (!(head))
        {
            head = p = temp;
            p->next = head;
        }
        else
        {
            p->next = temp;
            temp->prev = p;
            p = temp;
        }
        cout << "Node added! Create  another?(1/0) : ";
        cin >> ch;
    } while (ch != 0);
    return head;
}
void Display(LinkedList *p)
{
    if (p)
    {
        cout << p->data << "->";
        Display(p->next);
    }
    else
    {
        cout << "NULL\n";
        return;
    }
}
LinkedList *sortData(LinkedList *head)
{
    vector<int> temp;
    LinkedList *p = head;
    while (p)
    {
        temp.pb(p->data);
        p = p->next;
    }
    sort(temp.begin(), temp.end());
    p = head;
    int i = 0;
    while (p)
    {
        p->data = temp[i++];
        p = p->next;
    }
    return head;
}
class InsertTODLL
{
protected:
    int value;
    bool lock; //To prevent creating and overriding DLL.
    int choice;

public:
    LinkedList *head = nullptr;
    InsertTODLL()
    {
        this->lock = false;
        this->value = 0;
        this->choice = 0;
    }
    inline void updateLock()
    {
        lock = (lock) ? false : true;
    }
    void DisplayMenu()
    {
        cout << "Enter 1 to Create DLL\nEnter 2 to Sort the List\nEnter 3 to Display the List\nEnter 4 to Insert to list\nEnter 0 to exit()\n";
        bool freeMemLock = false;
        do
        {
            cout << "Enter choice : ";
            cin >> this->choice;
            switch (choice)
            {
            case 0:
                cout << "Terminating process... (" << getpid() << ")\n";
                FreeMem(&head);     //Freeup Space.
                freeMemLock = true; //Lock the func.
                break;
            case 1:
                if (!lock)
                {
                    head = CreateList(head);
                    cout << "DLL CREATED!\n";
                    updateLock(); //Acquire Instance Lock to prevent further list Creation!
                }
                else
                    cout << "Unable to create another DLL as it already exists!\n";
                break;
            case 2:
                head = sortData(head);
                break;
            case 3:
                cout << "\nInput List : ";
                Display(head);
                break;
            case 4:
                cout << "Insert to DLL\n";
                insertNode(&head);
                break;
            default:
                cout << "Invalid Choice! List deleted!\n";
                delete head;
                head = nullptr;
                updateLock();
                break;
            }
        } while (choice != 0);
        if (!freeMemLock)   //If freeMem Static method is not locked, invoke freeMem().
            FreeMem(&head); //Freeup Space.
    }
    void insertNode(LinkedList **head)
    {
        LinkedList *temp = new LinkedList(1 + rand() % 20);
        LinkedList *p = *head;

        if (!(*head))
        {
            *head = temp;
            temp->next = *head;
            cout << "List was empty, New Node added to List!\n";
            return;
        }
        // Shortcut
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
        cout << "Node Added to List!\n";
        *head = sortData(*head);
        return;
    }

    static void FreeMem(LinkedList **head)
    {
        if (!(*head))
        {
            cout << "No memory allocations found!";
        }
        LinkedList *temp = *head;
        static int counter = 0;
        while (temp != nullptr)
        {
            *head = (*head)->next;
            free(temp);
            counter++;
            temp = *head;
        }
        cout << "Memory Freed : " << counter * (sizeof(LinkedList)) << "bytes" << endl;
        return;
    }
};
//Driver Method.
int main()
{
    //Instance Created to Operate.
    cout << "Programing is running .... PID : " << getpid() << endl;
    InsertTODLL object;
    object.DisplayMenu();
    return 0;
}
