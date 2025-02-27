#include <stdio.h>
#include <string.h>

int isDivisibleBy(char *number, int divisor)
{
    int resto = 0;

    for (int i = 0; number[i] != '\0'; i++)
    {
        resto = (resto * 10 + (number[i] - '0')) % divisor;
    }

    return resto;
}

int main()
{
    char ano[10000];
    int gamb = 0;

    while (scanf("%s", ano) != EOF)
    {
        if (gamb)
        {
            printf("\n");
        }

        if ((isDivisibleBy(ano, 4) == 0 && isDivisibleBy(ano, 100) != 0) || (isDivisibleBy(ano, 400) == 0)) // é bissexto
        {
            printf("This is leap year.\n");

            if (isDivisibleBy(ano, 15) == 0) // é huluculu
            {
                printf("This is huluculu festival year.\n");
            }
            if (isDivisibleBy(ano, 55) == 0) // é bulukulu
            {
                printf("This is bulukulu festival year.\n");
            }
        }
        else // não é bissexto
        {
            if (isDivisibleBy(ano, 15) == 0) // é huluculu
            {
                printf("This is huluculu festival year.\n");
            }
            else
            {
                printf("This is an ordinary year.\n");
            }
        }

        gamb = 1;
    }
}
