#include <stdio.h>
#include <stdlib.h>

int maiorab(int a, int b)
{
    return (a + b + abs(a - b)) / 2;
}

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%d eh o maior\n", maiorab(maiorab(a, b), c));

    return 0;
}
