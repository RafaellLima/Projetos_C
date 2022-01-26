/*
    Esse programa pede ao usuário digitar a quantidade de balas ("skittles") que ele acredita estar
contida dentro de uma máqina de skittles.
    O programa termina quando o usuário adivinhar o número aleatório de skittles que há nela.
    Após cada vez que o código for executado, um número aleatório diferente será gerado.
    O número será um inteiro entre 0 e 1023 (inclusos).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(void)
{
    // Configurando o C para comportar a língua portuguesa, logo, ele considerará os acentos descritos.
    setlocale(LC_ALL, "Portuguese");

    // Declaração da variável "skittles", responsável por armazenar o número pseudo-aleatório gerado.
    int skittles;

    // Declaração da variável "palpite", responsável por armazenar o palpite do usuário.
    int palpite;

    // Declaração da seed do gerador de números pseudo-aleatórios.
    srand(time(NULL));

    // Geração de um número pseudo-aleatório entre 0 e 1023.
    skittles = rand() % 1024;


    // Loop em que se pede ao usuário digitar um número.
    // O loop continuará rodando até que ele acerte.
    // Após isso, é feita uma verificação utilizando bloco if-else, para checar se o usuário acertou ou não.
    do {
        printf("Tente acertar a quantidade de skittles que há na máquina: ");
        scanf("%i", &palpite);

        if(palpite == skittles){
            printf(" Parabéns! Você acertou, eu tenho %i skittles. \n", skittles);
        }
        else if(palpite > skittles && palpite < 1024){
            printf(" Eu não tenho tantos skittles... Não sou uma fábrica! \n");
        }
        else if(palpite < skittles && palpite >= 0){
            printf(" Eu tenho mais do que isso, afinal, sou uma máquina de skittles. \n");
        }
        else if(palpite < 0 || palpite > 1023){
            printf(" Você só pode chutar números entre 0 e 1023. Preste mais atenção! \n");
        }
    }
    while(palpite != skittles);

    return 0;
}