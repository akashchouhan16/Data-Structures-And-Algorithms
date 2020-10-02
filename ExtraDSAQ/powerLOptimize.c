#include <stdio.h>
// m^n
// Highly optimized code, where time complexity is min in all cases. eg: 2^9 requires 6 recursions instead of 9.
int power(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(m * m, n / 2);
    else
        return m * power(m * m, (n - 1) / 2);
}
int powerR(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return m * powerR(m, n - 1);
}
int main()
{
    printf("Enter the base and power : \n");
    int b, p;
    scanf("%d%d", &b, &p);
    printf("Value of %d raised to power %d is : %d\n", b, p, power(b, p));
    printf("Value of %d raised to power %d is : %d\n", b, p, powerR(b, p));
}