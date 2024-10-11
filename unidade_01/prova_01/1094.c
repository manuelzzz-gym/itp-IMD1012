#include <stdio.h>

double porcentagemPeloTotal(int total, int animal)
{
    return ((double)animal * 100.0) / total;
}

int main(int argc, char const *argv[])
{
    int n = 0, coelho = 0, rato = 0, sapo = 0, totalAnimais = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int quantia = 0;
        char tipo;

        scanf("%d %c", &quantia, &tipo);

        totalAnimais += quantia;

        if (tipo == 'C')
        {
            coelho += quantia;
        }
        else if (tipo == 'R')
        {
            rato += quantia;
        }
        else if (tipo == 'S')
        {
            sapo += quantia;
        }
    }

    printf("Total: %d cobaias\n", totalAnimais);
    printf("Total de coelhos: %d\n", coelho);
    printf("Total de ratos: %d\n", rato);
    printf("Total de sapos: %d\n", sapo);
    printf("Percentual de coelhos: %.2f %%\n", porcentagemPeloTotal(totalAnimais, coelho));
    printf("Percentual de ratos: %.2f %%\n", porcentagemPeloTotal(totalAnimais, rato));
    printf("Percentual de sapos: %.2f %%\n", porcentagemPeloTotal(totalAnimais, sapo));

    return 0;
}