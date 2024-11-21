#include <stdio.h>
#include <string.h>

void combinarPalavras(char palavra1[], char palavra2[])
{
    int tamanhoPalavra1 = strlen(palavra1);
    int tamanhoPalavra2 = strlen(palavra2);

    for (int i = 0; i < tamanhoPalavra1 || i < tamanhoPalavra2; i++)
    {
        if (i < tamanhoPalavra1)
        {
            printf("%c", palavra1[i]);
        }
        if (i < tamanhoPalavra2)
        {
            printf("%c", palavra2[i]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int numeroCasosTeste = 0;
    scanf("%d", &numeroCasosTeste);

    for (int i = 0; i < numeroCasosTeste; i++)
    {
        char palavra1[50], palavra2[50];
        scanf("%s %s", palavra1, palavra2);

        combinarPalavras(palavra1, palavra2);
    }

    return 0;
}
