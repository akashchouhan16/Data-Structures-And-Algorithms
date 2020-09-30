#include <stdio.h>

int checkpalindrome(int num)
{
    int res = 0, temp = num, digit = 0;
    while (temp != 0)
    {
        digit = temp % 10;
        res = res * 10 + digit;
        temp /= 10;
    }
    if (res == num)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    printf("Enter number to check whether it is palindrome : ");
    scanf("%d", &n);
    if (checkpalindrome(n))
        printf("Number is Palindrome!");
    else
        printf("Not a palindrome number.");
}