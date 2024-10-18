#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, positivos = 0;
    float input, media, total = 0;

    for (i = 0; i < 6; i++)
    {
        scanf("%f", &input);

        if (input > 0)
        {
            total += input;
            positivos++;
        }
    }

    media = total / positivos;

    printf("%d valores positivos\n", positivos);
    printf("%.1f\n", media);

    return 0;
}
