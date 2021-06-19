/* 
Teste de underflow da biblioteca a89stack.h

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
    printf(">>> Exibindo a pilha <<<\n");
    printf("%d ", pop(pilhaInt));
    printf("%d ", pop(pilhaInt));
    printf("%d ", pop(pilhaInt)); 
    printf("\n>>> Exibindo a pilha apos tirar tudo <<<\n");
    printf("%d ", pop(pilhaInt)); // underflow    
    printf("\nDestruindo a pilha\n"); 
    destroy(pilhaInt);
    return 0;
}
