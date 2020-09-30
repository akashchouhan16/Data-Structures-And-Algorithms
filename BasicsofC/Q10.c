#include <stdio.h>

int Fact(int num)
{
    if (num == 1 || num == 0)
        return 1;
    else
        return num * Fact(num - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("Factoria of %d is %d.", n, Fact(n));
}