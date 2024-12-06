#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

bool isPalindromo(char palavra[])
{
    toLowerCase(palavra);
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho / 2; i++)
    {
        if (palavra[i] != palavra[tamanho - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char palavra[100];
    scanf("%s", palavra);

    if (isPalindromo(palavra))
    {
        printf("Palíndromo\n");
    }
    else
    {
        printf("Não é um palíndromo\n");
    }

    return 0;
}