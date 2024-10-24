#include <stdio.h>

long long int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    long long int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main(int argc, char const *argv[])
{
    int casosTeste = 0;
    int n = 0;
    long long int x = 0;

    scanf("%d", &casosTeste);

    for (int i = 0; i < casosTeste; i++)
    {
        scanf("%d", &n);
        x = fib(n);

        printf("Fib(%d) = %lld\n", n, x);
    }

    return 0;
}