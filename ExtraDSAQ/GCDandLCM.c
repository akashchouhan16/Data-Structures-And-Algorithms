#include <stdio.h>
#include <math.h>
int GCD(int n1, int n2)
{
    if (n2 != 0)
        return GCD(n2, n1 % n2);
    else
        return n1;
}
int main()
{
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    printf("The HCf of %d and %d is %d\n", n1, n2, GCD(n1, n2));
    printf("The LCM of %d and %d is %d", n1, n2, (n1 * n2) / GCD(n1, n2));
}