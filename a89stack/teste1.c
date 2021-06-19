/* 
Teste 1 da biblioteca a89stack.h

arataca89@gmail.com
20210619
*/
#include "a89stack.h"

int main(){

    /* Teste de pilha int */
    Stack pilhaInt = create(3);
    Tipo n1, n2, n3;
    n1.i = 1;
    n2.i = 2;
    n3.i = 3;
    printf("\n>>> Testando pilha int <<<\n");
    printf("Pilha vazia? %d\n", isVoid(pilhaInt));
    printf("Pilha cheia? %d\n", isFull(pilhaInt));
    printf(">>> Inserindo itens na pilha <<<\n");
    push(n1,pilhaInt);
    push(n2,pilhaInt);
    push(n3,pilhaInt);
    printf("Pilha vazia? %d\n", isVoid(pilhaInt));
    printf("Pilha cheia? %d\n", isFull(pilhaInt));
    printf(">>> Exibindo a pilha <<<\n");
    printf("%d ", pop(pilhaInt));
    printf("%d ", pop(pilhaInt));
    printf("%d ", pop(pilhaInt)); 
    printf("\nDestruindo a pilha\n");    
    destroy(pilhaInt);

   /* Teste de pilha double */
    Stack pilhaFloat = create(3);
    Tipo f1, f2, f3;
    f1.f = 11.85;
    f2.f = 13.41;
    f3.f = 3.14;
    printf("\n>>> Testando pilha double <<<\n");
    printf("Pilha vazia? %d\n", isVoid(pilhaFloat));
    printf("Pilha cheia? %d\n", isFull(pilhaFloat));
    printf(">>> Inserindo itens na pilha <<<\n");
    push(f1,pilhaFloat);
    push(f2,pilhaFloat);
    push(f3,pilhaFloat);
    printf("Pilha vazia? %d\n", isVoid(pilhaFloat));
    printf("Pilha cheia? %d\n", isFull(pilhaFloat));
    printf(">>> Exibindo a pilha <<<\n");
    printf("%.2f ", pop(pilhaFloat));
    printf("%.2f ", pop(pilhaFloat));
    printf("%.2f ", pop(pilhaFloat)); 
    printf("\nDestruindo a pilha\n");    
    destroy(pilhaFloat);

   /* Teste de pilha char */
    Stack pilhaChar = create(3);
    Tipo c1, c2, c3;
    c1.c = 'a';
    c2.c = 'b';
    c3.c = 'c';
    printf("\n>>> Testando pilha char <<<\n");
    printf("Pilha vazia? %d\n", isVoid(pilhaChar));
    printf("Pilha cheia? %d\n", isFull(pilhaChar));
    printf(">>> Inserindo itens na pilha <<<\n");
    push(c1,pilhaChar);
    push(c2,pilhaChar);
    push(c3,pilhaChar);
    printf("Pilha vazia? %d\n", isVoid(pilhaChar));
    printf("Pilha cheia? %d\n", isFull(pilhaChar));
    printf(">>> Exibindo a pilha <<<\n");
    printf("%c ", pop(pilhaChar));
    printf("%c ", pop(pilhaChar));
    printf("%c ", pop(pilhaChar)); 
    printf("\nDestruindo a pilha\n");    
    destroy(pilhaChar);
    return 0;
}
