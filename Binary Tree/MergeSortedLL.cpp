#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} List;
// typedef Node List;

void CreateLL(List **head)
{
    List *temp = NULL, *p = *head;
    int ch;
    do
    {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        printf("Enter Data : ");
        scanf("%d", &temp->data);
        if (!(*head))
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
        cout << "Node Created! create Another?(1/0)";
        cin >> ch;
    } while (ch == 1);
    cout << "List Created!\n";
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
        printf("NULL\n");
        return;
    }
}
List *MergeSorted(List *head1, List *head2)
{
    List *third = NULL, *last = NULL;
    if (head1 == NULL)
    {
        third = head2;
        return third;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        third = last = head1;
        head1 = head1->next;
        last->next = NULL;
    }
    else if (head1->data > head2->data)
    {
        third = last = head2;
        head2 = head2->next;
        last->next = NULL;
    }
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            last->next = head1;
            last = head1;
            head1 = head1->next;
            last->next = NULL;
        }
        if (head2->data < head1->data)
        {
            last->next = head2;
            last = head2;
            head2 = head2->next;
            last->next = NULL;
        }
    }
    if (head1)
    {
        last->next = head1;
    }
    if (head2)
    {
        last->next = head2;
    }
    return third;
}

int main()
{
    List *head1 = NULL, *head2 = NULL;
    int ch;
    printf("Enter 1 to Create Singly Linked list1\nEnter 2 to Create Singly Linked list2\nEnetr 3 to Display List1\nEnetr 4 to Display List2\nEnter 5 to Merge and Display\nEnter 0 to exit().\n");
    do
    {
        printf("Enter choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            CreateLL(&head1);
        }
        else if (ch == 2)
        {
            CreateLL(&head2);
        }
        else if (ch == 3)
        {
            printf("List I : ");
            Display(head1);
        }
        else if (ch == 4)
        {
            printf("List II : ");
            Display(head2);
        }
        else if (ch == 5)
        {
            List *NewList = MergeSorted(head1, head2);
            cout << "\nMerge List : ";
            Display(NewList);
        }
        else
        {
            if (ch != 0)
                printf("Invalid Choice!\n");
            else
            {
                printf("Code Terminated!\n");
                break;
            }
        }
    } while (ch != 0);
    free(head1);
    free(head2);
    return 0;
}