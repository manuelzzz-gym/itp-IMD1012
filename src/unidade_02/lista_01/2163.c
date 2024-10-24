#include <stdio.h>

void posicaoSabre(int altura, int largura, int matriz[altura][largura], int *x, int *y)
{
    for (int i = 1; i < altura - 1; i++)
    {
        for (int j = 1; j < largura - 1; j++)
        {
            if (matriz[i][j] == 42)
            {
                if (matriz[i - 1][j - 1] == 7 && matriz[i - 1][j] == 7 && matriz[i - 1][j + 1] == 7 &&
                    matriz[i][j - 1] == 7 && matriz[i][j + 1] == 7 &&
                    matriz[i + 1][j - 1] == 7 && matriz[i + 1][j] == 7 && matriz[i + 1][j + 1] == 7)
                {
                    *x = i + 1;
                    *y = j + 1;
                    return;
                }
            }
        }
    }

    *x = 0, *y = 0;
}

int main(int argc, char const *argv[])
{
    int altura, largura;
    scanf("%d %d", &altura, &largura);

    int campoLuz[altura][largura];
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            scanf("%d", &campoLuz[i][j]);
        }
    }

    int x = 0, y = 0;
    posicaoSabre(altura, largura, campoLuz, &x, &y);
    printf("%d %d\n", x, y);

    return 0;
}
