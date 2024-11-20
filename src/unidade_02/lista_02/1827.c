#include <stdio.h>

void imprimirMatrizQuadrada(int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i == j && i == tamanho / 2)
            {
                printf("4");
            }
            else if (i >= tamanho / 3 && i < tamanho - tamanho / 3 && j >= tamanho / 3 && j < tamanho - tamanho / 3)
            {
                printf("1");
            }
            else if (i == j)
            {
                printf("2");
            }
            else if (i + j == tamanho - 1)
            {
                printf("3");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int tamanho = 0;

    while (scanf("%d", &tamanho) != EOF)
    {
        imprimirMatrizQuadrada(tamanho);
    }

    return 0;
}
