#include <stdio.h>

int main()
{
    int i, positivos = 0;
    float input;

    for (i = 0; i < 6; i++)
    {
        scanf("%f", &input);

        if (input > 0)
        {
            positivos++;
        }
    }

    printf("%d valores positivos\n", positivos);

    return 0;
}
