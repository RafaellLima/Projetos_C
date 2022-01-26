#include <cs50.h>
#include <stdio.h>

/*Função checksum: calcula a soma de verificação pelo algoritmo de Luhn*/
int checksum(long ccnum)
{
    long digito = ccnum;
    long restante = ccnum;
    int somadigito = 0;

    while (restante > 9)
    {
        //Pega o segundo dígito da direita para a esquerda e multiplica por 2
        digito = ((restante % 100) / 10);
        digito = digito * 2;

        //Se o produto resultar em dois dígitos, soma-os
        if (digito > 9)
        {
            digito = (digito / 10) + (digito % 10);
        }

        //Acumula os dígitos
        somadigito += digito;

        //Retira dois dígitos
        restante = restante / 100;
    }

    restante = ccnum;

    while (restante > 0)
    {
        //Pega o primeiro dígito da direita para a esquerda
        digito = (restante % 10);

        //Acumula os dígitos
        somadigito += digito;

        //Retira dois dígitos
        restante = restante / 100;
    }

    return somadigito;
}

int main(void)
{

    while (true)
    {
        long ccnum = get_long("Número: ");

        if (ccnum > 0)
        {

            int cs = checksum(ccnum);

            //Verifica se possui menos de 13 dígitos e se o checksum é inválido (para ser válido, último dígito deve ser zero)
            if ((ccnum / 1000000000000) < 1 || (cs % 10) > 0)
            {
                printf("INVALID\n");
            }
            //Verifica os dois primeiros dígitos do número que possui 16 dígitos
            else if ((ccnum / 100000000000000) == 51 || (ccnum / 100000000000000) == 52 || (ccnum / 100000000000000) == 53
                    || (ccnum / 100000000000000) == 54 || (ccnum / 100000000000000) == 55)
            {
                printf("MASTERCARD\n");
            }
            //Verifica os dois primeiros dígitos do número que possui 15 dígitos
            else if ((ccnum / 10000000000000) == 34 || (ccnum / 10000000000000) == 37)
            {
                printf("AMEX\n");
            }
            //Verifica o primeiro dígito do número que possui 13 ou 16 dígitos
            else if ((ccnum / 1000000000000) == 4 || (ccnum / 1000000000000000) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

            break;
        }
    }
}