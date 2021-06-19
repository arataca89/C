/* 
Teste de overflow da biblioteca a89stack.h

arataca89@gmail.com
20210619
*/
#include "a89stack.h"

int main(){
    Stack pilhaInt = create(3);
    int n1, n2, n3;
    n1 = 1;
    n2 = 2;
    n3 = 3;
    printf(">>> Inserindo itens na pilha <<<\n");
    pushInt(n1,pilhaInt);
    pushInt(n2,pilhaInt);
    pushInt(n3,pilhaInt);
    printf("\n>>> Tentando inserir alem da capacidade da pilha <<<\n");
    pushInt(4,pilhaInt); // overflow
    printf("\nDestruindo a pilha\n");    
    destroy(pilhaInt);
    return 0;
}
