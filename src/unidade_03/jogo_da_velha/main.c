#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tabuleiro.h"
#include "jogador.h"

int main(int argc, char const *argv[])
{

    Tabuleiro tabuleiro;

    Jogador jogadorReal;
    jogadorReal.simbolo = 'X';

    Jogador jogadorMaquina;
    jogadorMaquina.simbolo = 'O';

    iniciarTabuleiro(&tabuleiro, &jogadorReal, &jogadorMaquina);

    POSICOES posicaoJogada;
    Jogador vencedor;
    while (1)
    {
        exibirTabuleiro(&tabuleiro);

        if (tabuleiro.rodada == JOGADOR1)
        {
            int posicaoEscolhida = 0;
            printf("Digite a posicao: ");
            scanf("%d", &posicaoEscolhida);

            if (posicaoEscolhida < 1 || posicaoEscolhida > 9)
            {
                printf("Posicao invalida!\n");
                continue;
            }
            posicaoJogada = posicaoEscolhida - 1;

            if (isPosicaoMarcada(&tabuleiro, posicaoJogada))
            {
                printf("Posicao ja marcada!\n");
                continue;
            }

            marcarTabuleiro(&tabuleiro, posicaoJogada, &jogadorReal);
        }
        else
        {
            jogadaMaquina(&tabuleiro);
        }

        vencedor = verificarVencedor(&tabuleiro);

        if (vencedor.simbolo == jogadorReal.simbolo)
        {
            exibirTabuleiro(&tabuleiro);
            printf("Voce venceu!\n");
            break;
        }
        else if (vencedor.simbolo == jogadorMaquina.simbolo)
        {
            exibirTabuleiro(&tabuleiro);
            printf("Voce perdeu!\n");
            break;
        }
        else
        {
            if (isTabuleiroCheio(&tabuleiro))
            {
                printf("Empate!\n");
                break;
            }
        }

        atualizarRodada(&tabuleiro);
    }

    return 0;
}
