/********************************************************************
Nome: typedef.c
Descrição: Demonstra o uso da palavra-chave typedef
Data: 20210507

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 


A palavra-chave typedef cria um alias (um apelido) para um tipo de
dados, seja ele um tipo primitivo ou uma estrutura criada pelo
usuário.

Isto facilita tornando o código mais legível e portável. 

Legível porque em vez de usar "struct NOME" passamos a usar somente
o alias.

Portável porque bastará alterar uma linha no código para compilar 
em outro sistema cujo tamanho do tipo primitivo seja diferente.
Segundo Deitel(2011), "...um programa que exige inteiros de 4 bytes
pode usar o tipo int em um sistema e o tipo long em outro.
Os programas projetados para portabilidade normalmente usam typedef
para criar um alias para inteiros de 4 bytes, como Integer.
O alias Integer pode ser alterado uma vez no programa para fazê-lo
funcionar nos dois sistemas".

Referências:
Schildt(1997)
Deitel e Deitel(2011)

********************************************************************/

#include <stdio.h>

typedef int Inteiro; // Define o alias Inteiro para o tipo int.
typedef double Real; // Define o alias Real para o tipo double.

struct nave {
    Inteiro x;
    Inteiro y;
    Real power;
};

// Define o alias Nave para struct nave.
typedef struct nave Nave;

int main(){
    Nave n1;
    n1.x = 11;
    n1.y = 85;
    n1.power = 13.41;

    printf("Posicao: (%d, %d)\n",n1.x, n1.y); // Posicao: (11, 85)
    printf("Forca  : %.2f\n", n1.power); // Força  : 13.41

    return 0;
}
/********************************************************************
arataca89@gmail.com
Aulas particulaes de programação em C/C++ 
********************************************************************/
