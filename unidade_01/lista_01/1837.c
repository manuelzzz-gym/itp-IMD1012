#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);

    int q = a / b;
    int r = a % b;

    if (r < 0)
    {
        if (b > 0)
        {
            q--;
            r += b;
        }
        else
        {
            q++;
            r -= b;
        }
    }

    printf("%d %d\n", q, r);

    return 0;
}
