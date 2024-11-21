#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimirCaracteresMaisFrequentes(char palavra[])
{
    int frequencia[26] = {0};
    int maiorFrequencia = 0;

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (isalpha(palavra[i]))
        {
            int indice = tolower(palavra[i]) - 'a';
            frequencia[indice]++;
            if (frequencia[indice] > maiorFrequencia)
            {
                maiorFrequencia = frequencia[indice];
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (frequencia[i] == maiorFrequencia)
        {
            printf("%c", 'a' + i);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        char linha[201];
        fgets(linha, sizeof(linha), stdin); // Ler a linha de texto
        imprimirCaracteresMaisFrequentes(linha);
    }

    return 0;
}