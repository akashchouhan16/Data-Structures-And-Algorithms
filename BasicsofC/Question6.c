#include <stdio.h>

int main()
{
    int num, a = 1, b = 0, flag = -1;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (flag == -1)
    {
        int temp = a;
        a = a + b;
        b = temp;

        if (num == a)
        {
            flag++;
        }
        else if (num < a)
        {
            flag--;
        }
    }

    if (flag == 0)
    {
        printf("\nThe number is in Fibonacci Series.\n");
    }
    else if (flag == -2)
    {
        printf("\nThe number is not in Fibonacci Series.\n");
    }

    return 0;
}