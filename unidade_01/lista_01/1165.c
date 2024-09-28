#include <stdio.h>
#include <stdbool.h>

bool primo(int a)
{
    int i;

    for (i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int n, i, a;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);

        if (primo(a))
        {
            printf("%d eh primo\n", a);
        }
        else
        {
            printf("%d nao eh primo\n", a);
        }
    }

    return 0;
}
