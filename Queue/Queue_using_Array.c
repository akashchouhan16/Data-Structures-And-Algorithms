/*Queue is a Logical Data Structure where the insertion takes place from rear end, and deletion takes place from
    front end. Time Complexity : O(n) for Enqueue(), Dequeue(), isFULL(), isEMPTY(), peek(), etc.
    a) Follows FIFO principle(First in first Out)
    b) Analogy : Line at a ticket Counter, Printer connected to multiple users, etc.
    */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int front;
    int rear;
    int capacity;
    int *queue;
} Queue;

void Initialize(Queue **q)
{
    printf("Enter the Capacity : ");
    scanf("%d", &((*q)->capacity));
    (*q)->queue = (int *)malloc(sizeof(int) * ((*q)->capacity));

    (*q)->front = -1;
    (*q)->rear = -1;
    printf("Queue Init Complete.\n");
    return;
}

int Enqueue(Queue **q, int x)
{
    if ((*q)->rear >= ((*q)->capacity - 1))
    {
        printf("Queue is Full.\n");
        return 1;
    }
    else if ((*q)->front == -1)
    {
        (*q)->front++;
        (*q)->rear++;
        (*q)->queue[(*q)->rear] = x;
        return 0;
    }
    else
    {
        (*q)->rear++;
        (*q)->queue[(*q)->rear] = x;
        return 0;
    }
}
int Dequeue(Queue **q, int *m)
{
    if ((*q)->front == -1 || ((*q)->front > (*q)->rear))
    {
        printf("Queue is Empty.\n");
        *m = -1;
        return 1; //Unsuccessful Dequeue.
    }
    else if ((*q)->front == (*q)->rear)
    {
        (*q)->front = (*q)->rear = -1;
    }
    else
    {
        *m = (*q)->queue[(*q)->front];
        (*q)->front++;
        return 0;
    }
}
void Display(Queue *q)
{
    printf("Current Queue : ");
    if (q->front == -1 && q->rear == -1)
    {
        printf("Empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
    return;
}
int main()
{
    Queue *q;
    Initialize(&q);

    srand(time(0));
    int ch; //Choice.
    printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to Display.\nEnter 0 to Terminate\n");
    do
    {
        printf("Enter the Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int x;
            x = 1 + rand() % 9;
            Enqueue(&q, x);
        }
        else if (ch == 2)
        {
            int m;
            Dequeue(&q, &m);
            printf("\n%d Dequeued\n", m);
        }
        else if (ch == 3)
        {
            Display(q);
        }
    } while (ch != 0);

    free(q->queue);
    return 0;
}