#include <stdio.h>
#include <stdbool.h>

bool isTriangle(int ladoA, int ladoB, int ladoC)
{
    if (ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA)
        return true;

    return false;
}

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (isTriangle(a, b, c) || isTriangle(a, b, d) || isTriangle(a, c, d) || isTriangle(b, c, d))
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
