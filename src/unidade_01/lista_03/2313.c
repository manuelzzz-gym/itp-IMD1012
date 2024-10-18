#include <stdio.h>
#include <stdbool.h>

bool isTriangulo(int ladoA, int ladoB, int ladoC)
{
    if (ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA)
    {
        return true;
    }

    return false;
}

char isTrianguloRetangulo(int ladoA, int ladoB, int ladoC)
{
    if (isTriangulo(ladoA, ladoB, ladoC))
    {
        if (ladoA * ladoA == ladoB * ladoB + ladoC * ladoC || ladoB * ladoB == ladoA * ladoA + ladoC * ladoC || ladoC * ladoC == ladoA * ladoA + ladoB * ladoB)
        {
            return 'S';
        }
    }

    return 'N';
}

char *tipoTriangulo(int ladoA, int ladoB, int ladoC)
{
    if (isTriangulo(ladoA, ladoB, ladoC))
    {
        if (ladoA == ladoB && ladoB == ladoC)
        {
            return "Valido-Equilatero";
        }
        else if (ladoA == ladoB || ladoB == ladoC || ladoA == ladoC)
        {
            return "Valido-Isoceles";
        }
        else
        {
            return "Valido-Escaleno";
        }
    }

    return "Invalido";
}

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (isTriangulo(a, b, c))
    {
        printf("%s\n", tipoTriangulo(a, b, c));
        printf("Retangulo: %c\n", isTrianguloRetangulo(a, b, c));
        return 0;
    }

    printf("Invalido\n");
    return 0;
}
