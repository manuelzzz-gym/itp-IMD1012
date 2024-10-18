#include <stdio.h>

float price(int codigo, int quantidade)
{
    switch (codigo)
    {
    case 1001:
        return 1.5 * quantidade;
    case 1002:
        return 2.5 * quantidade;
    case 1003:
        return 3.5 * quantidade;
    case 1004:
        return 4.5 * quantidade;
    case 1005:
        return 5.5 * quantidade;
    default:
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    float total = 0;
    int n, codigo, quantidade;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &codigo, &quantidade);
        total += price(codigo, quantidade);
    }

    printf("%.2f\n", total);

    return 0;
}
