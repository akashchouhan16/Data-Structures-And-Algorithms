#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void Enqueue(int x)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Queue Overflow.\n");
        return;
    }
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
        return;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        return;
    }
}
void Dequeue(int *m)
{
    *m = -1;
    if (front == NULL || rear == NULL)
    {
        printf("Queue Underflow.\n");
    }
    else if (front != rear)
    {
        *m = front->data;
        front = front->next;
    }
    else if (front == rear) //single node
    {
        *m = front->data;
        free(front);
        free(rear);
        front = NULL;
        rear = NULL;
    }

    return;
}
void Display()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty.\n");
        return;
    }
    else
    {
        struct Node *temp = front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    return;
}
int isempty()
{
    if (!front)
        return 1;
    return 0;
}
int isFull()
{
    //since nodes are created in the Heap.
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
        return 1;
    free(temp);
    return 0;
}
int main()
{
    int m, ch, x;
    printf("Enter 1 to Enqueque\nEnter 2 to Dequeue\nEnter 3 to Display\nEnter 4 to check isempty()\nEnter 0 to exit.\n");
    do
    {
        printf("Enter choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter Data : ");
            scanf("%d", &x);
            Enqueue(x);
        }
        else if (ch == 2)
        {
            Dequeue(&m);
            printf("%d Dequequed.\n", m);
        }
        else if (ch == 3)
        {
            Display();
        }
        else if (ch == 4)
        {
            if (isempty())
                printf("Queue is Empty.\n");
            else
                printf("Queue is not empty.\n");
        }
        else
            break;
    } while (ch != 0);

    free(front);
    free(rear);
    return 0;
}