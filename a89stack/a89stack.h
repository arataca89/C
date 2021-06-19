/*
a89stack.h
Posui estruturas e funções que auxiliam a implementar pilhas.

Referências:
PEREIRA, S. L. Estrutura de Dados em C. 1a Edição. São Paulo: Saraiva.
FEOFILOFF, P. Algoritmos em Linguagem C. Rio de Janiero: Elsevier.
DEITEL, P.;DEITEL, H. C Como Programar. 6a Edição. São Paulo: Pearson Prentice Hall, 2011.
SCHILDT, H. C Completo e Total. 3a Edição. São Paulo: Makron Books, 1996.
TANENBAUM, A. M.;LANGSAM, Y.;AUGENSTEIN, M. J. Estruturas de Dados Usando C. São Paulo: Pearson Makron Books, 1995.

arataca89@gmail.com
20210619
*/
#ifndef A89STACK_H
#define A89STACK_H

#include <stdio.h>
#include <stdlib.h>

/* Define se a pilha será int, float ou char */
typedef union tipo{
    int i;
    double f;
    char c;
}Tipo;

/* Estrutura de dados que define a pilha */ 
typedef struct stack{
    int cap; 
    int top;
    Tipo *item; 
}*Stack;

/* Cria a pilha */
Stack create(int n){
    Stack pilha = (Stack) malloc(sizeof(struct stack));
    if(pilha == NULL){
        printf("\nERROR: Failed to allocate stack\n");
        exit(1);
    }
    pilha->cap = n;
    pilha->top = -1;
    pilha->item = (Tipo*) malloc(sizeof(Tipo));
    if(pilha->item == NULL){
        printf("\nERROR: Failed to allocate stack's type\n");
        exit(1);                
    }
    return pilha;
}

/* Verifica se a pilha está vazia */
int isVoid(Stack pilha){
    return pilha->top == -1;
}

/* Verifica se a pilha está cheia */
int isFull(Stack pilha){
    return pilha->top == pilha->cap - 1;
}

/* Insere um item na pilha */
void push(Tipo n, Stack pilha){
    if(isFull(pilha)){
        printf("\nERROR: stack overflow.\n");
        exit(1);
    }
    pilha->top++;
    pilha->item[pilha->top] = n;
}

/* Insere um int na pilha */
void pushInt(int n, Stack pilha){
    if(isFull(pilha)){
        printf("\nERROR: stack overflow.\n");
        exit(1);
    }
    pilha->top++;
    pilha->item[pilha->top].i = n;
}

/* Insere um float na pilha */
void pushFloat(double n, Stack pilha){
    if(isFull(pilha)){
        printf("\nERROR: stack overflow.\n");
        exit(1);
    }
    pilha->top++;
    pilha->item[pilha->top].f = n;
}

/* Insere um char na pilha */
void pushChar(char n, Stack pilha){
    if(isFull(pilha)){
        printf("\nERROR: stack overflow.\n");
        exit(1);
    }
    pilha->top++;
    pilha->item[pilha->top].c = n;
}

/* Retira e retorna o item do topo da pilha */
Tipo pop(Stack pilha){
    if(isVoid(pilha)){
        printf("\nERROR: stack underflow.\n");
        exit(1);

    }
    Tipo n = pilha->item[pilha->top];
    pilha->top--;
    return n;
}

/* Retorna o item que está no topo da pilha */
Tipo top(Stack pilha){
    if(isVoid(pilha)){
        printf("\nERROR: stack underflow.\n");
        exit(1);
    }
    return pilha->item[pilha->top];
}

/* Destrói a pilha */
void destroy(Stack pilha){
    free(pilha->item);
    free(pilha);
    pilha = NULL;
}

#endif
// fim de a89stack.h
