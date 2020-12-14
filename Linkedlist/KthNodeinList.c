#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node **head)
{
    struct Node *temp = NULL, *p = *head;
    int ch, n1, n2;
    printf("Enter Range (n1 to n2) : ");
    scanf("%d%d", &n1, &n2);
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        temp->data = n1 + rand() % (n2 - n1 + 1);
        if (*head == NULL)
        {
            *head = p = temp;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
        printf("Create Another?(1/0) : ");
        scanf("%d", &ch);
    } while (ch == 1);
    return;
}
void Display(struct Node *p)
{
    if (p)
    {
        printf("%d->", p->data);
        Display(p->next);
    }
    else
        printf("NULL\n");
}
struct Node *KthNode(struct Node *head, int key)
{
    if (key < 0)
        return NULL;
    struct Node *p = head;
    int i = 0;
    while (i++ < key)
    {
        p = p->next;
    }
    return p;
    return NULL;
}
int main()
{
    struct Node *head = NULL;
    Create(&head);
    int index;
    printf("List : ");
    Display(head);
    printf("\nEnter kth index : ");
    scanf("%d", &index);
    struct Node *result = KthNode(head, index);
    if (result)
        printf("%dth Node in the list : %d\n", index, result->data);
    else
        printf("%dth Node Not Found\n", index);
    free(head);
    return 0;
}