#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float reais;
    do
    {
        reais = get_float("Troco devido: ");
    }
    while (reais < 0);
    int centavos = round(reais * 100);


    int moeda = 0;

    while (centavos != 0)
    {
        //25
        moeda += centavos / 25;
        centavos = centavos % 25;
        // 10 conto
        moeda += centavos / 10;
        centavos %= 10;
        // 5 conto
        moeda += centavos / 5;
        centavos %= 5;
        // 1 conto
        moeda += centavos / 1;
        centavos %= 1;
    }

    printf("%d \n", moeda);
}



