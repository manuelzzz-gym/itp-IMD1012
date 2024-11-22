#include <stdio.h>

double soma(double matriz[5][5])
{
    double soma = 0.0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            soma += matriz[i][j];
        }
    }
    return soma;
}

double media(double matriz[5][5])
{
    return soma(matriz) / 10.0;
}

int main()
{
    char operacao;
    double matriz[5][5];
    int contador;

    scanf("%c", &operacao);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%lf", &matriz[i][j]);
        }
    }

    if (operacao == 'S')
    {
        printf("%.1lf\n", soma(matriz));
    }
    else if (operacao == 'M')
    {
        printf("%.1lf\n", media(matriz));
    }

    return 0;
}
