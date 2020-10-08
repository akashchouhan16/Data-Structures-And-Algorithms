//Not the Correct way to implement Priorirty Queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
void priorityInsert(int);
void priorityDelete(int);
void initialize();
void check(int);
void display_pqueue();
int pri_que[MAX];
int front, rear;

void initialize()
{
    front = rear = -1;
}

void priorityInsert(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

void check(int data)
{
    int i, j;

    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

void priorityDelete(int data)
{
    int i;

    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }

    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }

            pri_que[i] = -99;
            rear--;

            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}

void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }

    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }

    front = 0;
}

int main()
{
    int n, ch;

    printf("\n1 To Insert an element into queue");
    printf("\n2 To Delete an element from queue");
    printf("\n3 To Display queue elements");
    printf("\n0 To Exit");

    initialize();

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to be inserted : ");
            scanf("%d", &n);
            priorityInsert(n);
            break;
        case 2:
            printf("Enter value to delete : ");
            scanf("%d", &n);
            priorityDelete(n);
            break;
        case 3:
            display_pqueue();
            break;
        case 0:
            exit(0);
        default:
            printf("\nIncorrect Choice, Enter a correct choice");
        }
    }
    return 0;
}