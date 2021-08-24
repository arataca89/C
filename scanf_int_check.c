/********************************************************************
Nome: scanf_int_check.c
Descrição:  Demonstra uma maneira de verificar se o usuario entrou
            com um inteiro.

Data: 20210824

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 

Fonte:
https://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c

********************************************************************/

#include <stdio.h>

int main(){        
    int n;
    char newline;

    printf("Entre com um inteiro: ");

    if(scanf("%d%c", &n, &newline) != 2 || newline != '\n')
        printf("ERRO:voce nao entrou com um inteiro.\n");
    else
        printf("OK ... voce entrou com: %d\n", n);

    return 0;
}
/********************************************************************
 arataca89@gmail.com
 Aulas particulaes de programação em C/C++ 
 *******************************************************************/