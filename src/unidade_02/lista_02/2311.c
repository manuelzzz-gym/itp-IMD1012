#include <stdio.h>

typedef struct
{
    char nome[100];
    double dificuldade;
    double notas[7];
    double notaFinal;
} Jogador;

Jogador setJogador()
{
    Jogador jogador;
    scanf("%s", jogador.nome);
    scanf("%lf", &jogador.dificuldade);
    for (int i = 0; i < 7; i++)
    {
        scanf("%lf", &jogador.notas[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (jogador.notas[i] < jogador.notas[j])
            {
                double temp = jogador.notas[i];
                jogador.notas[i] = jogador.notas[j];
                jogador.notas[j] = temp;
            }
        }
    }

    return jogador;
}

int main(int argc, char const *argv[])
{
    int numeroJogadores = 0;
    scanf("%d", &numeroJogadores);

    while (numeroJogadores--)
    {
        Jogador jogador = setJogador();
        jogador.notaFinal = 0;
        for (int i = 1; i < 6; i++)
        {
            jogador.notaFinal += jogador.notas[i];
        }
        jogador.notaFinal *= jogador.dificuldade;
        printf("%s %.2lf\n", jogador.nome, jogador.notaFinal);
    }

    return 0;
}
