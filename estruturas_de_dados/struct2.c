/********************************************************************
Nome: struct2.c
Descrição: Como passar membros de estruturas ou a própria estrutura
           para funções.
Data: 20210507

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 


Como passar membros de estruturas ou a própria estrutura
para funções.

Referências:
Schildt(1997)
Deitel e Deitel(2011)

********************************************************************/

#include <stdio.h>

// Aqui a estrutura foi definida e criado o alias Produto para ela.
typedef struct{
   char *descricao;
   int quantidade;
   float preco; 
} Produto;

// Esta função receberá o membro quantidade sendo passado por valor.
// Assim o membro não será modificado na estrutura. 
int subtrair(int qtde, int n){
    return qtde - n;
}

// Aqui o membro quantidade será passado por referência,
// assim será alterado na estrutura.
void retirar(int *membro, int n){
    *membro -= n; // Aqui membro, que é um ponteiro para int,
                  // foi desreferenciado (*membro).
                  // Assim o valor apontado pode ser acessado
                  // e modificado.
}

/*
Aqui a estrutura é passada por referência. 
Este é o método indicado para grandes estruturas.
A passagem por referência proporciona uma melhor performance
pois evita o overhead de passar uma cópia de toda a estrutura,
o que é feito na passagem por valor.
Observe a utilização do operador seta (->) para acessar 
os membros da estrutura. Neste caso ele foi usado em 
vez do ponto (.) pois o acesso é através de um
ponteiro.
*/
void alterar(Produto *p){
    p->descricao = "Monitor LCD";
    p->quantidade = 50;
    p->preco = 2500.70;
}

int main(){
    Produto p1;

    p1.descricao = "Monitor";
    p1.quantidade = 20;
    p1.preco = 1300.50;

    printf("%s\t%d\t%.2f\n",p1.descricao,p1.quantidade,p1.preco);

    // Passando um membro da estrutura por valor.
    printf("Se vender 5 monitores o novo saldo sera: %d\n", subtrair(p1.quantidade, 5));
    printf("Como foi passado por valor a quantidade ainda e %d\n", p1.quantidade);

    // Passando um membro da estrutura por referência.
    // Neste caso o valor do membro é alterado na estrutura.
    printf("Reduzindo a quantidade em 5 unidades.\n");
    retirar(&p1.quantidade, 5);
    printf("Agora a quantidade e %d\n", p1.quantidade);

    // Passando toda a estrutura por referência.
    printf("\nPassando a estrutura por referencia e alterando os membros:\n");
    alterar(&p1);
    printf("%s\t%d\t%.2f\n",p1.descricao,p1.quantidade,p1.preco);

    return 0;

}
/********************************************************************

SAIDA:

Monitor	20	1300.50
Se vender 5 monitores o novo saldo sera: 15
Como foi passado por valor a quantidade ainda e 20
Reduzindo a quantidade em 5 unidades.
Agora a quantidade e 15

Passando a estrutura por referencia e alterando os membros:
Monitor LCD	50	2500.70

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 
********************************************************************/
