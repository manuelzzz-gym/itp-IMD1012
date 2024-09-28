#include <stdio.h>
#include <string.h>
int values[] = {
    1000,
    900,
    500,
    400,
    100,
    90,
    50,
    40,
    10,
    9,
    5,
    4,
    1,
};

char *symbols[] = {
    "M",
    "CM",
    "D",
    "CD",
    "C",
    "XC",
    "L",
    "XL",
    "X",
    "IX",
    "V",
    "IV",
    "I",
};

void paraRomano(int num, char *romano)
{
    int i = 0;
    romano[0] = '\0';

    while (num > 0)
    {
        while (num >= values[i])
        {
            strcat(romano, symbols[i]);
            num -= values[i];
        }

        i++;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    char romano[10];

    scanf("%d", &n);

    paraRomano(n, romano);

    printf("%s\n", romano);

    return 0;
}