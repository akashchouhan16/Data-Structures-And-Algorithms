#include <stdio.h>
//Wap to test whether a number is present in the fibonacci series.

int FibNumcheck(int num)
{
    int flag = 0, a = 0, b = 1, c = 1;
    if (num == a || num == b)
        return 1;
    while (flag == 0)
    {
        a = b;
        b = c;
        c = a + b;
        if (num == c)
        {
            flag = 1;
            break;
        }
        if (num < c)
            break;
    }
    return flag;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (FibNumcheck(n) == 1)
        printf("Number %d present in the fibonacci series.", n);
    else
        printf("Number %d is not present n the fibonacci series.", n);
}