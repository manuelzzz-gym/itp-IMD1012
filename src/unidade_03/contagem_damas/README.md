# Solução da segunda questão do projeto da Unidade 03

## Enunciado:

Faça um programa em C para colocar N rainhas em um tabuleiro de xadrez de tamanho N × N,
de forma que nenhuma rainha possa atacar outra. Isso significa que nenhuma rainha deve
compartilhar a mesma linha, coluna ou diagonal com outra. O programa deve perguntar ao usuário
o tamanho do tabuleiro e em seguida gerar o tabuleiro NxN com as N rainhas posicionadas.
Exemplo de saída em um tabuleiro 8x8

|     | a   | b   | c   | d   | e   | f   | g   | h   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1   | Q   |     |     |     |     |     |     |     |
| 2   |     |     |     | Q   |     |     |     |     |
| 3   |     |     |     |     |     |     |     | Q   |
| 4   |     |     |     |     |     | Q   |     |     |
| 5   |     | Q   |     |     |     |     |     |     |
| 6   |     |     |     |     |     |     | Q   |     |
| 7   |     |     | Q   |     |     |     |     |     |
| 8   |     |     |     |     | Q   |     |     |     |

## Solução:

1. A função `verificacao` checa se é seguro colocar uma dama na posição (linha, coluna), garantindo que nenhuma outra dama já esteja na mesma coluna ou diagonais.
2. A função `solucao` tenta recursivamente colocar damas linha por linha.
3. Em cada linha, testa todas as colunas com a função `verificacao`; se for seguro, coloca a dama e chama recursivamente para a próxima linha.
4. Se não houver conflitante, retorna sucesso (1). Caso contrário, remove a dama (backtracking) e tenta a próxima coluna.
5. Quando as damas são colocadas com sucesso em todas as linhas, é encontrada a solução para o problema.
