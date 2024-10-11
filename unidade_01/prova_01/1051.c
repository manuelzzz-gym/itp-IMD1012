#include <stdio.h>

double imposto(float valor, float imposto)
{
    return valor * imposto / 100;
}

double impostoLisarb(double valor)
{
    double impostoTotal = 0.0;

    if (valor <= 2000.00)
    {
        return 0.00;
    }
    else if (valor <= 3000.00)
    {
        impostoTotal += imposto(valor - 2000.00, 8);
    }
    else if (valor <= 4500.00)
    {
        impostoTotal += imposto(1000.00, 8);
        impostoTotal += imposto(valor - 3000.00, 18);
    }
    else
    {
        impostoTotal += imposto(1000.00, 8);
        impostoTotal += imposto(1500.00, 18);
        impostoTotal += imposto(valor - 4500.00, 28);
    }

    return impostoTotal;
}
int main(int argc, char const *argv[])
{
    float salario;
    scanf("%f", &salario);

    double impostoCobrado = impostoLisarb(salario);

    if (impostoCobrado == 0.00)
    {
        printf("Isento\n");
    }
    else
    {
        printf("R$ %.2f\n", impostoCobrado);
    }

    return 0;
}
