#include <stdio.h>

int countdigit(int num)
{
    if (num == 0)
        return 0;
    else
        return 1 + countdigit(num / 10);
}
int main()
{
    int num;
    scanf("%d", &num);
    printf("Number of digits are : %d ", countdigit(num));
}