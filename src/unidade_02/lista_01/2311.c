#include <stdio.h>
#include <stdbool.h>

int posicaoMaiorOuMenor(double notas[], int tamanho, bool buscandoMaior)
{
    int posicao = 0;
    for (int i = 1; i < tamanho; i++)
    {
        if ((buscandoMaior && notas[i] > notas[posicao]) || (!buscandoMaior && notas[i] < notas[posicao]))
        {
            posicao = i;
        }
    }
    return posicao;
}

int main(int argc, char const *argv[])
{
    int numeroParticipantes;
    scanf("%d", &numeroParticipantes);

    double grauDificuldade[numeroParticipantes];
    double notas[numeroParticipantes][7];
    char nomeParticipantes[numeroParticipantes][30];

    for (int i = 0; i < numeroParticipantes; i++)
    {
        scanf("%s", nomeParticipantes[i]);
        scanf("%lf", &grauDificuldade[i]);
        for (int j = 0; j < 7; j++)
        {
            scanf("%lf", &notas[i][j]);
        }
    }

    double notasFinais[numeroParticipantes];
    for (int i = 0; i < numeroParticipantes; i++)
    {
        int posicaoMaior = posicaoMaiorOuMenor(notas[i], 7, true);
        int posicaoMenor = posicaoMaiorOuMenor(notas[i], 7, false);

        double somaNotas = 0;
        for (int j = 0; j < 7; j++)
        {
            if (j != posicaoMaior && j != posicaoMenor)
            {
                somaNotas += notas[i][j];
            }
        }
        notasFinais[i] = somaNotas * grauDificuldade[i];
    }

    for (int i = 0; i < numeroParticipantes; i++)
    {
        printf("%s %.2lf\n", nomeParticipantes[i], notasFinais[i]);
    }

    return 0;
}