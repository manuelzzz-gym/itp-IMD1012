#include <stdio.h>
#include <string.h>

int quadrado(int n)
{
    return n * n;
}

int resolverPalavra(char palavra[])
{
    if (palavra[0] == palavra[2])
    {
        return quadrado(palavra[0] - '0');
    }

    if (palavra[1] >= 'A' && palavra[1] <= 'Z')
    {
        return palavra[2] - palavra[0];
    }

    return palavra[0] + palavra[2] - '0' - '0';
}

int main(int argc, char const *argv[])
{
    int numeroCasosTeste = 0;
    scanf("%d", &numeroCasosTeste);

    for (int i = 0; i < numeroCasosTeste; i++)
    {
        char palavra[4];
        scanf("%s", palavra);

        printf("%d\n", resolverPalavra(palavra));
    }

    return 0;
}
