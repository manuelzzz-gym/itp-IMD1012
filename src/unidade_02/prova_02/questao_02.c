#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindromo(char *palavra)
{
    int i = 0;
    int j = 0;
    while (palavra[j] != '\0')
    {
        j++;
    }
    j--;

    while (i < j)
    {
        while (i < j && !isalpha(palavra[i]))
        {
            i++;
        }
        while (i < j && !isalpha(palavra[j]))
        {
            j--;
        }

        if (tolower(palavra[i]) != tolower(palavra[j]))
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    char palavra[100];
    fgets(palavra, sizeof(palavra), stdin);

    palavra[strcspn(palavra, "\n")] = '\0';

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