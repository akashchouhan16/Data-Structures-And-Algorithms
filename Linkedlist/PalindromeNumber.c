#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void NumReverse(int *num)
{
    int d = 0, rev = 0;
    while (*num)
    {
        d = *num % 10;
        rev = rev * 10 + d;
        *num = *num / 10;
    }
    *num = rev;
    return;
}
void Create(struct Node **head, int num)
{
    int digit = 0, rev = 0;
    struct Node *newnode = NULL, *p = *head;
    int temp = num;
    while (temp)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->next = NULL;
        digit = temp % 10;
        newnode->data = digit;
        temp /= 10;
        if (*head == NULL)
        {
            *head = p = newnode;
        }
        else
        {
            p->next = newnode;
            p = newnode;
        }
    }

    return;
}
int checkPalindrome(struct Node *h1, struct Node *h2)
{
    if (h1 == NULL || h2 == NULL)
    {
        printf("LL has not been created for a number\n");
        return 0;
    }
    while (h1 && h2)
    {
        if (h1->data != h2->data)
        {
            return 0; // Not Palindrome.
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return 1; //Is Palindrome.
}
int main()
{
    struct Node *num1 = NULL, *num2 = NULL;
    int n1;
    printf("Enter the Number : ");
    scanf("%d", &n1);
    Create(&num1, n1);
    NumReverse(&n1);
    Create(&num2, n1);
    int res = checkPalindrome(num1, num2);
    if (res)
    {
        printf("\nNumber is Palindrome.\n");
    }
    else
        printf("Number is Not Palinrome.\n");
    free(num1);
    free(num2);
    printf("**code terminated!** \n");
    return 0;
}
