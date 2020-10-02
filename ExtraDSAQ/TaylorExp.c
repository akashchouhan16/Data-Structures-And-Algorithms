#include <stdio.h>

double Exp(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    else
    {
        r = Exp(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}
double ExpR(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return ExpR(x, n - 1);
}
int main()
{
    printf("%lf \n", Exp(1, 10));
    printf("%lf \n", ExpR(1, 10));
}