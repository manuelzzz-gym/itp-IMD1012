#include <stdio.h>
#include <stdbool.h>

bool triangulo(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        return true;
    }

    return false;
}

char *tipoTriangulo(int a, int b, int c)
{
    if (triangulo(a, b, c))
    {
        if (a == b && b == c)
        {
            return "Equilatero";
        }
        else if (a == b || b == c || a == c)
        {
            return "Isoceles";
        }
        else
        {
            return "Escaleno";
        }
    }
}

char isRetangulo(int a, int b, int c)
{
    if (triangulo(a, b, c))
    {
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            return 'S';
        }
    }

    return 'N';
}

int main(int argc, char const *argv[])
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (triangulo(a, b, c))
    {
        printf("Valido-%s\n", tipoTriangulo(a, b, c));
        printf("Retangulo: %c\n", isRetangulo(a, b, c));
    }
    else
    {
        printf("Invalido\n");
    }

    return 0;
}
