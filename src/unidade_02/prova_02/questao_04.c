#include <stdio.h>

typedef enum
{
    APROVADO,
    RECUPERACAO,
    REPROVADO
} SituacaoAluno;

typedef struct
{
    char nome[100];
    double notas[4];
    double media;
    SituacaoAluno situacao;
} Aluno;

void setAluno(Aluno *aluno)
{
    // scanf("%s", aluno->nome);
    scanf("%lf %lf %lf", &aluno->notas[0], &aluno->notas[1], &aluno->notas[2]);

    aluno->media = 0;
    for (int i = 0; i < 3; i++)
    {
        aluno->media += aluno->notas[i];
    }
    aluno->media /= 3;

    if (aluno->media < 3)
    {
        aluno->situacao = REPROVADO;
        return;
    }

    if (aluno->media >= 7)
    {
        aluno->situacao = APROVADO;
    }
    else if (aluno->media >= 3)
    {
        aluno->situacao = RECUPERACAO;
        scanf("%lf", &aluno->notas[3]);

        int menorNotaIndex = 0;
        for (int i = 1; i < 3; i++)
        {
            if (aluno->notas[i] < aluno->notas[menorNotaIndex])
            {
                menorNotaIndex = i;
            }
        }
        aluno->notas[menorNotaIndex] = aluno->notas[3];

        aluno->media = 0;
        for (int i = 0; i < 3; i++)
        {
            aluno->media += aluno->notas[i];
        }
        aluno->media /= 3;

        if (aluno->media >= 7)
        {
            aluno->situacao = APROVADO;
        }
        else
        {
            aluno->situacao = REPROVADO;
        }
    }
}

int main()
{
    Aluno aluno;
    setAluno(&aluno);

    switch (aluno.situacao)
    {
    case APROVADO:
        printf("Aprovado\n");
        break;
    case RECUPERACAO:
        printf("Recuperacao\n");
        break;
    case REPROVADO:
        printf("Reprovado\n");
        break;
    }

    return 0;
}