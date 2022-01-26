#include <cs50.h>
#include <stdio.h>

int main(void)
{
     // Solicita um caracter para o usuário
     char c = get_char("Você concorda?");

     // Verifica se concordou
     if (c == 'S' || c == 's')
     {
         printf("Concorda.\n");
     }
     else if (c == 'N' || c == 'n')
     {
        printf("Não concorda.\n");
     }
}

// "||" significa 'OU' caso for maiusculo ou minusculo na ligaguem C.
// get_char() = para inserir um Caractere unico, ou seja, uma letra.
// tambem usar: '&&' = 'e', '||' = 'ou'.