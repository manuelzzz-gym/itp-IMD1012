#include <stdio.h>

int calcularHora(int a, int b, int c)
{
    int resultado = a + b + c;

    if (resultado >= 24)
    {
        resultado -= 24;
    }
    else if (resultado < 0)
    {
        resultado += 24;
    }

    return resultado;
}

int main(int argc, char const *argv[])
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int horaChegada = calcularHora(a, b, c);

    printf("%d\n", horaChegada);

    return 0;
}