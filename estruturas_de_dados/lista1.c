/*
Exemplo de lista encadeada simples com inserção no início.

arataca89@gmail.com
20210606

Referências:
JAMSA, K.;KLANDER, L. Programando em C/C++ "A Bíblia". São Paulo: Makron Books, 1999.
SCHILDT, H.. C Completo e Total. 3a Edição. São Paulo: Makron Books, 1996.
DEITEL, P.;DEITEL, H.. C Como Programar. 6a Edição. São Paulo: Pearson Prentice Hall, 2011.
TANENBAUM, A. M.;LANGSAM, Y.;AUGENSTEIN, M. J. Estruturas de Dados Usando C. São Paulo: Pearson Makron Books, 1995.
https://youtu.be/lgPgknuUK-s
*/
#include <stdio.h>
#include <stdlib.h>

/* estrutura que define um nó da lista */
struct Node{
    int valor;
    struct Node *proximo;/* ponteiro para outra estrutura Node */
};

/* Criando o alias(apelido) "node" para a estrutura "struct Node" */
typedef struct Node node; 

/* estrutura que define a lista encadeada */
typedef struct{
    node *inicio;
    int tamanho;
} Lista;

/* protótipos de funções */
node * criarNode(int);
void inserirNoInicio(Lista *, int);
void criarLista(Lista *, int);
void printDadosDaLista(Lista);
void printLista(Lista);
void freeLista(Lista);

int main(){
    Lista lista;
    lista.inicio = NULL;
    lista.tamanho = 0;

    /* iniciando a lista */
    criarLista(&lista, 13);

    /* inserindo nós no início da lista */
    inserirNoInicio(&lista, 41);
    printDadosDaLista(lista);

    inserirNoInicio(&lista, 11);
    printDadosDaLista(lista);

    inserirNoInicio(&lista, 85);
    printDadosDaLista(lista);

    printLista(lista);

    freeLista(lista);

    return 0;
}

node * criarNode(int nr){
    node *noh;
    noh = (node *)malloc(sizeof(node));
    noh->valor = nr;
    noh->proximo = NULL;
    return noh;    
}

void inserirNoInicio(Lista *lista, int nr){
    node *noh;
    noh = criarNode(nr);
    noh->proximo = lista->inicio;
    lista->inicio = noh;
    lista->tamanho++;
    printf("Inserido o valor %d no inicio da lista\n", nr);
}

void criarLista(Lista *lista, int nr){
    lista->inicio = criarNode(13);
    lista->tamanho++;
    printf("\nLista iniciada com o valor %d\n", nr);
    printf("Endereco do inicio da lista %p\n", lista->inicio);
    printf("\n");
}

void printDadosDaLista(Lista lista){
    printf("Endereco do inicio da lista : %p\n", lista.inicio);
    printf("Tamanho da lista            : %d\n", lista.tamanho);
    printf("\n");
}

void printLista(Lista lista){
    node *noh =  lista.inicio;  
    printf("Imprimindo os nos da lista\n");     
    printf("--------------------------\n\n");     
    while(noh->proximo != NULL){
        printf("endereco: %p\n", noh);
        printf("Valor   : %d\n", noh->valor);
        printf("proximo : %p\n\n", noh->proximo);
        noh = noh->proximo;        
    }

    /* primeiro nó da lista; noh->proximo == NULL */
    printf("endereco: %p\n", noh);
    printf("Valor   : %d\n", noh->valor);
    printf("proximo : %p\n\n", noh->proximo);
}

void freeLista(Lista lista){
    node *noh = lista.inicio;
    while(noh != NULL){
        free(noh);
        noh = noh->proximo;
    }

    /* primeiro nó da lista; noh->proximo == NULL */
    free(noh);
}

/*

SAIDA:

Lista iniciada com o valor 13
Endereco do inicio da lista 00000000007C13B0

Inserido o valor 41 no inicio da lista
Endereco do inicio da lista : 00000000007C6DD0
Tamanho da lista            : 2

Inserido o valor 11 no inicio da lista
Endereco do inicio da lista : 00000000007C6DF0
Tamanho da lista            : 3

Inserido o valor 85 no inicio da lista
Endereco do inicio da lista : 00000000007C6E10
Tamanho da lista            : 4

Imprimindo os nos da lista
--------------------------

endereco: 00000000007C6E10
Valor   : 85
proximo : 00000000007C6DF0

endereco: 00000000007C6DF0
Valor   : 11
proximo : 00000000007C6DD0

endereco: 00000000007C6DD0
Valor   : 41
proximo : 00000000007C13B0

endereco: 00000000007C13B0
Valor   : 13
proximo : 0000000000000000

*/
