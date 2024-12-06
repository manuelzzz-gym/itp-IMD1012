#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int vogais[5];
    int total;
} Vogais;

void contarNumeroVogais(Vogais *vogais, char c)
{
    int indice = -1;
    switch (c)
    {
    case 'a':
        indice = 0;
        break;
    case 'e':
        indice = 1;
        break;
    case 'i':
        indice = 2;
        break;
    case 'o':
        indice = 3;
        break;
    case 'u':
        indice = 4;
        break;
    }

    if (indice != -1)
    {
        vogais->vogais[indice]++;
        vogais->total++;
    }
}

int main()
{
    Vogais vogais = {0, 0, 0, 0, 0};
    char texto[100];

    scanf(" %[^\n]", texto);

    for (int i = 0; i < strlen(texto); i++)
    {
        texto[i] = tolower(texto[i]);
        contarNumeroVogais(&vogais, texto[i]);
    }

    printf("%d - %d - %d - %d - %d - %d\n", vogais.total, vogais.vogais[0], vogais.vogais[1], vogais.vogais[2],
           vogais.vogais[3], vogais.vogais[4]);

    return 0;
}