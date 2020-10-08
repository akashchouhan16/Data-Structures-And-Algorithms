#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *front = NULL, *rear = NULL;

void Enqueue(int end)
{
    struct Node *temp = NULL;
    int x;
    printf("Enter Data : ");
    scanf("%d", &x);
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = temp->prev = NULL;
    temp->data = x;
    if (end == 0)
    { //front inserion.

        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }
    else if (end == 1) //Insert at Rear end.
    {
        if (!front || !rear)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }
    return;
}
int Dequeue(int end, int *m)
{
    struct Node *p = front;
    if (end == 0) //deletion at front end.
    {
        if (front != NULL)
        {
            front = front->next;
            front->prev;
            *m = p->data;
            free(p);
            return 0;
        }
        else
        {
            printf("DEQueue is Empty.\n");
            *m = -1;
            return 1;
        }
    }
    else if (end == 1) //Deletion at rear End.
    {
        p = rear;
        if (rear != NULL)
        {
            *m = rear->data;
            rear = rear->prev;
            free(p);
            return 0;
        }
        else if (!rear)
        {
            printf("DEQUEUE is Empty\n");
            *m = -1;
            return 1;
        }
    }
}

void Display()
{
    struct Node *p = front;
    while (p != rear)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
    return;
}
int main()
{
    int ch, en = 0, m;
    printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 0 to Terminate\n");
    do
    {
        printf("Enter choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {

            printf("Enter End(0- front | 1- Rear) : ");
            scanf("%d", &en);
            Enqueue(en);
            Display();
        }
        else if (ch == 2)
        {

            printf("Enter End(0- front | 1- Rear) : ");
            scanf("%d", &en);
            Dequeue(en, &m);
            printf("%d Dequeued!\n", m);
            Display();
        }
    } while (ch != 0);
    free(front);
    free(rear);
    return 0;
}