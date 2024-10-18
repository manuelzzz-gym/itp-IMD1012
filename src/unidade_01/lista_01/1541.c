#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    while (true)
    {
        int a, b, c;

        scanf("%d ", &a);

        if (a == 0)
        {
            break;
        }

        scanf("%d %d ", &b, &c);

        int area_casa = a * b;
        double area_terreno = area_casa / (c / 100.0);
        int lado_terreno = sqrt(area_terreno);

        printf("%d\n", lado_terreno);
    }
    return 0;
}
