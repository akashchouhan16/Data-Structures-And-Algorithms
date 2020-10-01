//Circular Queue.
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//ADT
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void Enqueue(int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Queue Overflow.\n");
        return;
    }
    temp->data = x;
    temp->next = NULL;
    if (!front && !rear)
    {
        front = rear = temp;
        rear->next = front;
    }
    else
    {
        temp->next = front;
        rear->next = temp;
        rear = temp;
    }
    return;
}
void Dequeue(int *m)
{
    *m = -999;
    if (!front)
    {
        printf("Queue Underflow.\n");
        return;
    }
    else if (front != rear)
    {
        *m = front->data;
        rear->next = front->next;
        front = front->next;
    }
    else if (front == rear) //single node.
    {
        *m = front->data;
        free(front);
        free(rear);
        front = NULL;
        rear = NULL;
        return;
    }
    return;
}
void Display()
{
    printf("Current Queue : ");
    if (!front)
    {
        printf("Queue is Empty.\n");
        return;
    }
    else
    {
        struct Node *temp = front;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
    }
}
int main()
{
    int m, ch, x;
    printf("Enter 1 to Enqueque\nEnter 2 to Dequeue\nEnter 3 to Display\nEnter 0 to exit.\n");
    do
    {
        printf("\nEnter choice : ");
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
        else
            break;
    } while (ch != 0);

    Display();
    free(front);
    free(rear);
    return 0;
}