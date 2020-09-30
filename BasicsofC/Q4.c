//to find the first digit of a number;
#include <stdio.h>
#include <math.h>
int countdigit(int num)
{
    if (num == 0)
        return 0;
    else
        return 1 + countdigit(num / 10);
}
int findFirstdigit(int num)
{
    int digit = countdigit(num);
    return num / pow(10, (digit - 1));
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("First digit is %d", findFirstdigit(n));
}