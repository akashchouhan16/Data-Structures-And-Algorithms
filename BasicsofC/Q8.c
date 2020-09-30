#include <stdio.h>
//To make it more efficient, we can simply increase the res counter by adding the max(a,b) to it after each iteration instead of res++.
int LCM(int a, int b)
{
    int res = a > b ? a : b;
    for (; res < (a * b); res++)
    {
        if (res % a == 0 && res % b == 0)
            break;
    }
    return res;
}
int HCF(int a, int b)
{
    int res = a < b ? a : b;
    for (; res >= 1; res--)
        if (a & res == 0 && b % res == 0)
            break;

    return res;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    printf("LCM of %d and %d is %d", a, b, HCF(a, b));
}