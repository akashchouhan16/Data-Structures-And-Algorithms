//stack using array
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *st)
{
    printf("Enter the size of stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}
void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    printf("%d ",st.s[i]);
    printf("\n");
}
void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
    printf("Stack overflow\n");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
    printf("\nStack Underflow\n");
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    push(&st,60);
    push(&st,70);
    push(&st,80);
    push(&st,90);
    push(&st,100);
    display(st);
        printf("\n");
    printf("Deleted is:%d\n",pop(&st));    
    printf("Deleted is:%d\n",pop(&st));
    printf("\n-----After Deletion-----\n");
    display(st);
}
    
