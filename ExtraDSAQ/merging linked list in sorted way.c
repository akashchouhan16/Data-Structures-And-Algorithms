#include<stdio.h>             ///MERGE TWO SINGLE LINKED LISTS
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
void create1()
{
    struct Node *p;
    int i=1,n;
    printf("Enter data for node 1\n");
    scanf("%d",&first->data);
    first->next=NULL;
    p=first;
    printf("Enter Choice(1/0)\n");
    scanf("%d",&n);
    while(n)
    {
        p->next=(struct Node*)malloc(sizeof(struct Node));
        p=p->next;
        printf("Enter data for node %d\n",i+1);
        scanf("%d",&p->data);
        p->next=NULL;
        printf("Enter Choice(1/0)\n");
        scanf("%d",&n);
        i++;
    }

}
void create2()
{
    struct Node *q;
    int i=1,n;
    printf("Enter data for node 1\n");
    scanf("%d",&second->data);
    second->next=NULL;
    q=second;
    printf("Enter Choice(1/0)\n");
    scanf("%d",&n);
    while(n)
    {
        q->next=(struct Node*)malloc(sizeof(struct Node));
        q=q->next;
        printf("Enter data for node %d\n",i+1);
        scanf("%d",&q->data);
        q->next=NULL;
        printf("Enter Choice(1/0)\n");
        scanf("%d",&n);
        i++;
    }

}
void merge()
{
    struct Node *last;
    if(first->data<second->data)
    {
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else
    {
        third=last=second;
        second=second->next;
        last->next=NULL;
    }
    while(first && second)
    {

        if(first->data<second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
        if(first!=NULL){last->next=first;}
        else{last->next=second;}
    }
}
void display1()
{
    struct Node *m=first;
    while(m)
    {
        printf("%d ",m->data);
        m=m->next;
    }
}
void display2()
{
    struct Node *n=second;
    while(n)
    {
        printf("%d ",n->data);
        n=n->next;
    }
}
void display3()
{
    struct Node *a=third;
    while(a)
    {
        printf("%d ",a->data);
        a=a->next;
    }
}
int main()
{
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    create1();
    create2();
    printf("First Linked List:\n");
    display1();
    printf("\nSecond Linked List:\n");
    display2();
    merge();
    printf("\nMerged Linked list\n");
    display3();

}
