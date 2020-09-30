#include <stdio.h>

int Rpower(int b, int p)
{
    if (p == 1)
        return b;
    else
        return b * Rpower(b, p - 1);
}

int main()
{
    int base, power;
    scanf("%d%d", &base, &power);
    printf("%d to the power %d is %d", base, power, Rpower(base, power));
}