#include <stdio.h>

double fibo(int n)
{
    return (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    printf("%.1f\n", fibo(n));

    return 0;
}
