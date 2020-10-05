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
    int num = 0, digit = 0, rev = 0;
    struct Node *newnode = NULL, *p = *head;
    printf("Enter the Number : ");
    scanf("%d", &num);
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
    Create(&num1);
    Create(&num2);
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