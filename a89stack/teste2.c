/* 
Teste 2  da biblioteca a89stack.h

arataca89@gmail.com
20210619
*/
#include "a89stack.h"

int main(){

    /* Teste de pilha int */
    Stack pilhaInt = create(3);
    int n1, n2, n3;
    n1 = 1;
    n2 = 2;
    n3 = 3;
    printf("\n>>> Testando pilha int <<<\n");
    printf("Pilha vazia? %d\n", isVoid(pilhaInt));
    printf("Pilha cheia? %d\n", isFull(pilhaInt));
    printf(">>> Inserindo itens na pilha <<<\n");
    pushInt(n1,pilhaInt);
    pushInt(n2,pilhaInt);
    pushInt(n3,pilhaInt);
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
    double f1, f2, f3;
    f1 = 11.85;
    f2 = 13.41;
    f3 = 3.14;
    printf("\n>>> Testando pilha double <<<\n");
    printf("Pilha vazia? %d\n", isVoid(pilhaFloat));
    printf("Pilha cheia? %d\n", isFull(pilhaFloat));
    printf(">>> Inserindo itens na pilha <<<\n");
    pushFloat(f1,pilhaFloat);
    pushFloat(f2,pilhaFloat);
    pushFloat(f3,pilhaFloat);
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
    char c1, c2, c3;
    c1 = 'a';
    c2 = 'b';
    c3 = 'c';
    printf("\n>>> Testando pilha char <<<\n");
    printf("Pilha vazia? %d\n", isVoid(pilhaChar));
    printf("Pilha cheia? %d\n", isFull(pilhaChar));
    printf(">>> Inserindo itens na pilha <<<\n");
    pushChar(c1,pilhaChar);
    pushChar(c2,pilhaChar);
    pushChar(c3,pilhaChar);
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
