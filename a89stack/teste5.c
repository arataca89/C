/* 
Teste da função top() da biblioteca a89stack.h
arataca89@gmail.com
20210619
*/
#include "a89stack.h"

int main(){
    Stack pilhaInt = create(3);
    Tipo n1, n2, n3;
    n1.i = 1;
    n2.i = 2;
    n3.i = 3;
    printf("\n>>> Testando pilha int <<<\n");
    printf(">>> Inserindo itens na pilha <<<\n");
    push(n1,pilhaInt);
    push(n2,pilhaInt);
    push(n3,pilhaInt);
    printf("\n>>> Exibindo item do topo da pilha: %d\n", top(pilhaInt));
    printf(">>> Retirando um item da pilha <<<\n");
    printf("%d ", pop(pilhaInt));
    printf("\n>>> Exibindo item do topo da pilha: %d\n", top(pilhaInt));
    printf(">>> Retirando um item da pilha <<<\n");
    printf("%d ", pop(pilhaInt));
    printf("\n>>> Exibindo item do topo da pilha: %d\n", top(pilhaInt));
    printf(">>> Retirando um item da pilha <<<\n");
    printf("%d ", pop(pilhaInt));

    printf("\n\nDestruindo a pilha\n");    
    destroy(pilhaInt);
    return 0;
}