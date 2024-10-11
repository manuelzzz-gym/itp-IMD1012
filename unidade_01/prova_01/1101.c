#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int x, y;
    int soma;

    while (true)
    {
        scanf("%d %d", &x, &y);

        if (x <= 0 || y <= 0)
        {
            break;
        }

        if (x > y)
        {
            soma = 0;
            for (int i = y; i <= x; i++)
            {
                printf("%d ", i);
                soma += i;
            }
            printf("Sum=%d\n", soma);
        }
        else
        {
            soma = 0;
            for (int i = x; i <= y; i++)
            {
                printf("%d ", i);
                soma += i;
            }
            printf("Sum=%d\n", soma);
        }
    }

    return 0;
}
