/********************************************************************
Nome: struct1.c
Descrição: Demonstra a criação de tipos de dados definidos pelo
           usuário usando struct.
Data: 20210506

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 

********************************************************************/

#include <stdio.h>

// Cria o tipo de dados livro.
struct livro{
    char *titulo;
    int paginas;
    double preco;
};

int main(){

    // Declara a variável l1 como do tipo livro e inicializa
    // a estrutura.
    struct livro l1 = {"C a Linguagem de Programação", 279, 185.50};
    
    // Declara a variável l2 como do tipo livro e inicializa
    // cada campo utilizando o operador . (ponto).
    struct livro l2;
    l2.titulo = "C Como Programar";
    l2.paginas = 818;
    l2.preco = 246.40;

    // Utilizando um ponteiro para a estrutura.
    struct livro l3 = {"C Completo e Total", 827, 311.99};
    struct livro *livroPtr;
    livroPtr = &l3;

    // Observe a utilização do oeprador . (ponto) para acessar
    // os membros da estrutura.
    printf("{%s, %d, %.2f}\n",l1.titulo, l1.paginas, l1.preco );
    printf("{%s, %d, %.2f}\n",l2.titulo, l2.paginas, l2.preco );

    // Caso utilize ponteiros o acesso aos membros da estrutura se dá através
    // do operador -> (seta)
    printf("{%s, %d, %.2f}\n",livroPtr->titulo, livroPtr->paginas,livroPtr->preco );

    // Outra maneira de acessar os membros através do ponteiro.
    printf("{%s, %d, %.2f}\n",(*livroPtr).titulo, (*livroPtr).paginas,(*livroPtr).preco );

    return 0;
}
/********************************************************************

SAÍDA:

{C a Linguagem de Programação, 279, 185.50}
{C Como Programar, 818, 246.40}
{C Completo e Total, 827, 311.99}
{C Completo e Total, 827, 311.99}


arataca89@gmail.com
Aulas particulaes de programação em C/C++ 
********************************************************************/
