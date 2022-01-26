#include <stdio.h>
#include <cs50.h>

int main(void)
{
//Digite valor o tamanho da piramide
    int a;
    do
    {
        a = get_int(" largura: ");
    }

    while (!(a >= 1 && a <= 8));
// altura maior ou igual 1 e altura menor ou igual 8,
// enquanto não for válido vai continua o loop repetindo novo numero inteiro.
    /*
    ...#  <--- fileira 1, 1 altura com 3 espaço
    ..##  <--- fileira 2, 2 altura com 2 espaço
    .###  <--- fileira 3, 3 altura com 1 espaço
    ####  <--- fileira 4, 4 altura (0 excluido na condição porque "espaço = 1")
    para cada linha temos espaços + hashtag = total altura => total altura - hashtag
    */
    for (int fileira = 1; fileira <= a; fileira++)
    {
//Imprimir espaço p/ alinhar
        for (int espaço = 1; espaço <= a - fileira; espaço++)
        {
            printf(" ");
        }
//Imprimir hashtag p/ cada linha
//Imprimir número de linha de vezes
        for (int j = 1; j <= fileira; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}




