#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "jogador.h"

typedef enum
{
    posicao1,
    posicao2,
    posicao3,
    posicao4,
    posicao5,
    posicao6,
    posicao7,
    posicao8,
    posicao9
} POSICOES;

typedef enum
{
    JOGADOR1,
    JOGADOR2
} RODADA;

typedef struct
{
    char **tabuleiro;
    Jogador *jogador1;
    Jogador *jogador2;
    RODADA rodada;
} Tabuleiro;

void iniciarTabuleiro(Tabuleiro *tabuleiro, Jogador *jogadorReal, Jogador *jogadorMaquina)
{
    tabuleiro->jogador1 = jogadorReal;
    tabuleiro->jogador2 = jogadorMaquina;
    tabuleiro->rodada = JOGADOR1;

    tabuleiro->tabuleiro = (char **)malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
    {
        tabuleiro->tabuleiro[i] = (char *)malloc(3 * sizeof(char));
        for (int j = 0; j < 3; j++)
        {
            tabuleiro->tabuleiro[i][j] = '1' + (i * 3) + j;
        }
    }
}

void marcarTabuleiro(Tabuleiro *tabuleiro, POSICOES posicao, Jogador *jogador)
{
    switch (posicao)
    {
    case posicao1:
        tabuleiro->tabuleiro[0][0] = jogador->simbolo;
        break;
    case posicao2:
        tabuleiro->tabuleiro[0][1] = jogador->simbolo;
        break;
    case posicao3:
        tabuleiro->tabuleiro[0][2] = jogador->simbolo;
        break;
    case posicao4:
        tabuleiro->tabuleiro[1][0] = jogador->simbolo;
        break;
    case posicao5:
        tabuleiro->tabuleiro[1][1] = jogador->simbolo;
        break;
    case posicao6:
        tabuleiro->tabuleiro[1][2] = jogador->simbolo;
        break;
    case posicao7:
        tabuleiro->tabuleiro[2][0] = jogador->simbolo;
        break;
    case posicao8:
        tabuleiro->tabuleiro[2][1] = jogador->simbolo;
        break;
    case posicao9:
        tabuleiro->tabuleiro[2][2] = jogador->simbolo;
        break;
    default:
        break;
    }
}

bool isPosicaoMarcada(Tabuleiro *tabuleiro, POSICOES posicao)
{
    switch (posicao)
    {
    case posicao1:
        return tabuleiro->tabuleiro[0][0] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[0][0] == tabuleiro->jogador2->simbolo;
    case posicao2:
        return tabuleiro->tabuleiro[0][1] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[0][1] == tabuleiro->jogador2->simbolo;
    case posicao3:
        return tabuleiro->tabuleiro[0][2] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[0][2] == tabuleiro->jogador2->simbolo;
    case posicao4:
        return tabuleiro->tabuleiro[1][0] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[1][0] == tabuleiro->jogador2->simbolo;
    case posicao5:
        return tabuleiro->tabuleiro[1][1] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[1][1] == tabuleiro->jogador2->simbolo;
    case posicao6:
        return tabuleiro->tabuleiro[1][2] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[1][2] == tabuleiro->jogador2->simbolo;
    case posicao7:
        return tabuleiro->tabuleiro[2][0] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[2][0] == tabuleiro->jogador2->simbolo;
    case posicao8:
        return tabuleiro->tabuleiro[2][1] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[2][1] == tabuleiro->jogador2->simbolo;
    case posicao9:
        return tabuleiro->tabuleiro[2][2] == tabuleiro->jogador1->simbolo || tabuleiro->tabuleiro[2][2] == tabuleiro->jogador2->simbolo;
    }
}

void jogadaMaquina(Tabuleiro *tabuleiro)
{
    srand(time(NULL));
    bool posicaoValida = false;

    while (!posicaoValida)
    {
        POSICOES posicaoJogada = rand() % 9 + 1;

        posicaoValida = !isPosicaoMarcada(tabuleiro, posicaoJogada);

        if (posicaoValida)
        {
            marcarTabuleiro(tabuleiro, posicaoJogada, *&tabuleiro->jogador2);
        }
    }
}

void atualizarRodada(Tabuleiro *tabuleiro)
{
    if (tabuleiro->rodada == JOGADOR1)
    {
        tabuleiro->rodada = JOGADOR2;
    }
    else
    {
        tabuleiro->rodada = JOGADOR1;
    }
}

void exibirTabuleiro(Tabuleiro *tabuleiro)
{
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro->tabuleiro[0][0], tabuleiro->tabuleiro[0][1], tabuleiro->tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro->tabuleiro[1][0], tabuleiro->tabuleiro[1][1], tabuleiro->tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro->tabuleiro[2][0], tabuleiro->tabuleiro[2][1], tabuleiro->tabuleiro[2][2]);
    printf("\n");
}

bool isTabuleiroCheio(Tabuleiro *tabuleiro)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro->tabuleiro[i][j] != tabuleiro->jogador1->simbolo && tabuleiro->tabuleiro[i][j] != tabuleiro->jogador2->simbolo)
            {
                return false;
            }
        }
    }

    return true;
}

Jogador verificarVencedor(Tabuleiro *tabuleiro)
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro->tabuleiro[i][0] == tabuleiro->tabuleiro[i][1] && tabuleiro->tabuleiro[i][1] == tabuleiro->tabuleiro[i][2])
        {
            if (tabuleiro->tabuleiro[i][0] == tabuleiro->jogador1->simbolo)
            {
                return *(tabuleiro->jogador1);
            }
            else if (tabuleiro->tabuleiro[i][0] == tabuleiro->jogador2->simbolo)
            {
                return *(tabuleiro->jogador2);
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro->tabuleiro[0][i] == tabuleiro->tabuleiro[1][i] && tabuleiro->tabuleiro[1][i] == tabuleiro->tabuleiro[2][i])
        {
            if (tabuleiro->tabuleiro[0][i] == tabuleiro->jogador1->simbolo)
            {
                return *(tabuleiro->jogador1);
            }
            else if (tabuleiro->tabuleiro[0][i] == tabuleiro->jogador2->simbolo)
            {
                return *(tabuleiro->jogador2);
            }
        }
    }

    if (tabuleiro->tabuleiro[0][0] == tabuleiro->tabuleiro[1][1] && tabuleiro->tabuleiro[1][1] == tabuleiro->tabuleiro[2][2])
    {
        if (tabuleiro->tabuleiro[0][0] == tabuleiro->jogador1->simbolo)
        {
            return *(tabuleiro->jogador1);
        }
        else if (tabuleiro->tabuleiro[0][0] == tabuleiro->jogador2->simbolo)
        {
            return *(tabuleiro->jogador2);
        }
    }

    if (tabuleiro->tabuleiro[0][2] == tabuleiro->tabuleiro[1][1] && tabuleiro->tabuleiro[1][1] == tabuleiro->tabuleiro[2][0])
    {
        if (tabuleiro->tabuleiro[0][2] == tabuleiro->jogador1->simbolo)
        {
            return *(tabuleiro->jogador1);
        }
        else if (tabuleiro->tabuleiro[0][2] == tabuleiro->jogador2->simbolo)
        {
            return *(tabuleiro->jogador2);
        }
    }

    Jogador nenhum;
    nenhum.simbolo = ' ';
    return nenhum;
}
