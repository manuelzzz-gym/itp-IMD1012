# Solução da primeira questão do projeto da Unidade 03

## Enunciado:

Faça um programa em C que simule o jogo da velha. O programa deve gerar o tabuleiro (3x3)
enumerados de 1 a 9 inicialmente e a medida que o jogador escolha a posição você deve substituir o
número da posição por X. Exemplo:

|  |  |  |
| - | - | - |
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |

Escolha sua posição, jogador X: 5

|  |  |  |
| - | - | - |
| 1 | 2 | 3 |
| 4 | X | 6 |
| 7 | 8 | 9 |

O outro jogador será o PC. Ele escolherá uma posição aleatória, dentro das possíveis, e o tabuleiro
deve ser atualizado colocando o O na posição escolhida. Exemplo:

|  |  |  |
| - | - | - |
| 1 | 2 | O |
| 4 | X | 6 |
| 7 | 8 | 9 |

Ao final, o programa deve informar quem é o vencedor ou dizer se houve empate.

## Solução:

1. Cria-se um tabuleiro 3x3 alocado dinamicamente em "tabuleiro.h".  
2. Define-se uma estrutura de dados (Tabuleiro) que contém o tabuleiro e os jogadores, além do controle de rodada.  
3. Em "main.c", inicializa-se o tabuleiro e define-se os jogadores (com símbolos X e O).  
4. Na vez do jogador, o programa solicita a posição desejada; valida se está livre e marca. Em seguida, alterna a rodada.  
5. Sendo a vez da máquina, a função "jogadaMaquina" é chamada e a máquina faz uma jogada necessariamente válida e aleatória.
6. O jogo continua até que um jogador seja vencedor ou o tabuleiro fique cheio.
