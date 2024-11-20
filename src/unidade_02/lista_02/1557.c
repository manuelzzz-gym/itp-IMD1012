#include <stdio.h>

void imprimirMatriz(int tamanhoMatriz)
{
    int matriz[tamanhoMatriz][tamanhoMatriz];

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            if (i == 0 && j == 0)
            {
                matriz[i][j] = 1;
            }
            else if (j == 0)
            {
                matriz[i][j] = matriz[i - 1][j] * 2;
            }
            else
            {
                matriz[i][j] = matriz[i][j - 1] * 2;
            }
        }
    }

    int espacamento = 1;
    int valor = matriz[tamanhoMatriz - 1][tamanhoMatriz - 1];
    while (valor >= 10)
    {
        valor /= 10;
        espacamento++;
    }

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            printf("%*d", espacamento, matriz[i][j]);
            if (j < tamanhoMatriz - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int tamanho;
    while (scanf("%d", &tamanho) && tamanho != 0)
    {
        imprimirMatriz(tamanho);
        printf("\n");
    }
    return 0;
}