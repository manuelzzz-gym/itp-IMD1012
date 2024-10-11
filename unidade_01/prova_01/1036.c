#include <stdio.h>
#include <math.h>

void bhaskara(double a, double b, double c)
{
    double delta = b * b - 4 * a * c;

    if (delta < 0 || a * 2 == 0)
    {
        printf("Impossivel calcular\n");
        return;
    }

    double raiz1 = (-b + sqrt(delta)) / (2 * a);
    double raiz2 = (-b - sqrt(delta)) / (2 * a);

    printf("R1 = %.5f\n", raiz1);
    printf("R2 = %.5f\n", raiz2);
}

int main(int argc, char const *argv[])
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    bhaskara(a, b, c);

    return 0;
}
