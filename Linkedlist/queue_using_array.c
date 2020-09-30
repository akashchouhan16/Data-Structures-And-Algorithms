//queue implemented using array
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct 
{
    int data[MAX];
    int front;
    int rear;
} QUEUE;

int insert(QUEUE* q, int val) 
{
    if (q->rear == MAX - 1) 
    {
        return 1;
    }
    if (q->front == -1) 
    {
        q->front = q->rear = 0;
    } 
    else 
    {
        ++q->rear;
    }
    q->data[q->rear] = val;
    return 0;
}

int delete_static(QUEUE* q, int* del) 
{
    if (q->front == -1) 
    {
        return 1;
    }
    *del = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    } 
    else 
    {
        ++q->front;
    }
    return 0;
}
int delete_shift(QUEUE* q, int* del) 
{
    if (q->front == -1) 
    {
        return 1;
    }
    *del = q->data[q->front];
    if (q->front == q->rear) 
    {
        q->front = q->rear = -1;
    }
    else
    {
        for (int i = q->rear; i >= q->front; --i) 
        {
            q->data[i + 1] = q->data[i];
        }
    }
    return 0;
}

int main() 
{
    QUEUE q;
    q.front = q.rear = -1;
    int val = rand() % 10;
    if (insert(&q, val) != 0) 
    {
        printf("QUEUE Overflow\n");
    }
    else 
    {
        printf("%d inserted successfully\n", val);
    }

    int del;
    if (delete_static(&q, &del) != 0) 
    {
        printf("QUEUE Underflow\n");
    } 
    else 
    {
        printf("%d deleted successfully\n", del);
    }
    return 0;
}

