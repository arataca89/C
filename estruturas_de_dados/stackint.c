/*
Implementação de uma pilha estática de inteiros

1. Definição do tamanho da pilha, pois trata-se de uma pilha
   estática, ou seja, a alocação de memória para a pilha será feita
   em tempo de compilação;
2. Definição da estrutura de pilha;
3. Declaração de uma variável do tipo da pilha;
4. Função isEmpty() que verifica se a pilha está vazia;
5. Função pop() que remove um item do topo da pilha;
6. Função push() que insere um item no topo da pilha;
7. Função returnTop() que retorna o item no topo da pilha;
8. Função main() para testar as funcionalidades.

arataca89@gmail.com
20210510

Referências:
TANENBAUM;LANGSAM;AUGENSTEIN. Estruturas de Dados Usando C.
São Paulo: Pearson Makron Books, 1995

SCHILDT. C Completo e Total. 3a Edição
São Paulo: Makron Books, 1996.

DEITEL;DEITEL. C Como Programar. 6a Edição.
São Paulo: Pearson Prentice Hall, 2011.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct stack{
    int top;
    int items[SIZE];
} Stack;

Stack pilha;

int isEmpty(const Stack *s);
int pop(Stack *s);
void push(Stack *s, int n);
int returnTop(Stack *s);
void exibir(Stack *s);

int main(){
    int item, opcao = 0;
    pilha.top = -1;

    do{
        printf("\nPilha de inteiros\n");
        printf("----------------\n");
        printf("<< 1 >> Exibir a pilha\n");
        printf("<< 2 >> Inserir item na pilha.\n");
        printf("<< 3 >> Retirar item da pilha.\n");
        printf("<< 4 >> Exibir item do topo.\n");
        printf("<< -1 >> Sair.\n");

        printf("Entre com sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                exibir(&pilha);
                break;
            case 2:
                printf("Entre com o valor a ser inserido: ");
                scanf("%d", &item);
                while( getchar() != '\n' );
                push(&pilha, item);
                break;
            case 3:
                item = pop(&pilha);
                printf("Item retirado da pilha: %d\n",item);
                break;
            case 4:
                printf("Item do topo da pilha: %d\n", returnTop(&pilha));
                break;
            case -1:
                return 0;
            default:
                printf("Opcao invalida.\n");
        }

    } while(item != -1);

}

int isEmpty(const Stack *s){
    return s->top == -1;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Pilha vazia.\n");
        return 0;
    }
    return s->items[s->top--];    
}

void push(Stack *s, int n){
    if(s->top == SIZE - 1){
        printf("ERRO: pilha cheia.\n");
        return;
    }
    s->items[++s->top] = n;
}

int returnTop(Stack *s){
    if(isEmpty(s)){
        printf("Pilha vazia.\n");
        return 0;
    }
    return s->items[s->top];  
}

void exibir(Stack *s){
    if(isEmpty(s)){
        printf("Pilha vazia.\n");
        return;
    }
    printf("BASE ");
    for(int i = 0; i <= s->top; i++){
        printf("%d ", s->items[i]);
    }
    printf("TOPO\n");
}
/* fim de stackint.c */
