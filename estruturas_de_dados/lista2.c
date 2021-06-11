/*
Exemplo de lista encadeada simples com menu para manipular a lista.
Opções de menu:
    - exibir lista;
    - inserção no início;
    - inserção no final;
    - retirar do início;
    - retirar do final;
    - retirar determinado valor;
    - exibir dados da lista;
    - encerrar.

Referências:
JAMSA, K.;KLANDER, L. Programando em C/C++ "A Bíblia". São Paulo: Makron Books, 1999.
SCHILDT, H. C Completo e Total. 3a Edição. São Paulo: Makron Books, 1996.
DEITEL, P.;DEITEL, H. C Como Programar. 6a Edição. São Paulo: Pearson Prentice Hall, 2011.
TANENBAUM, A. M.;LANGSAM, Y.;AUGENSTEIN, M. J. Estruturas de Dados Usando C. São Paulo: Pearson Makron Books, 1995.

arataca89@gmail.com
20210611
*/
#include <stdio.h>
#include <stdlib.h>

/* estrutura que define um nó da lista */
struct Node{
    int valor;
    struct Node *proximo;
    struct Node *anterior;
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
void criarLista(Lista *, int);
void inserirNoInicio(Lista *, int);
void inserirNoFim(Lista *, int);
void retirarDoInicio(Lista *);
void retirarDoFim(Lista *);
void retirarItem(Lista *, int);
void printDadosDaLista(Lista);
void printLista(Lista);
void freeLista(Lista);


int main(){
    Lista lista;
    lista.inicio = NULL;
    lista.tamanho = 0;
    int opcao = -1;
    int n;

    printf("\n>>> Lista encadeada simples <<<\n");
    printf("\nCriando lista. Entre com o primeiro inteiro da lista: ");
    scanf("%d", &n);     
    criarLista(&lista,n);

    do {
        printf("\n");
        printf("<< 1 >> Exibir lista\n");
        printf("<< 2 >> Inserir no inicio da lista\n");
        printf("<< 3 >> Inserir no fim da lista\n");
        printf("<< 4 >> Retirar do inicio da lista\n");
        printf("<< 5 >> Retirar do  fim da lista\n");
        printf("<< 6 >> Retirar determinado item da lista\n");
        printf("<< 7 >> Exibir dados da lista\n");
        printf("<< 0 >> Encerrar\n");
        printf("\nEntre com sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                break;
            case 1:
                printLista(lista);
                break;
            case 2:
                printf("\nEntre com o inteiro a ser inserido no inicio da lista: ");
                scanf("%d", &n);
                inserirNoInicio(&lista, n);  
                break;          
            case 3:
                printf("\nEntre com o inteiro a ser inserido no fim da lista: ");
                scanf("%d", &n);
                inserirNoFim(&lista, n);  
                break; 
            case 4:
                retirarDoInicio(&lista);
                break;
            case 5:
                retirarDoFim(&lista);
                break;
            case 6:
                printf("\nEntre com o valor a ser retirado da lista: ");
                scanf("%d", &n);
                retirarItem(&lista, n);
                break;
            case 7:
                printDadosDaLista(lista);
                break;           
            default:
                printf("\n>>> Opcao invalida <<<\n");
        }
    } while(opcao != 0);

    printf("\nBons estudos!!!\n");
    printf("\narataca89@gmail.com\n");
    freeLista(lista);
    return 0;
}

node * criarNode(int nr){
    node *noh;
    noh = (node *)malloc(sizeof(node));
    noh->valor = nr;
    noh->proximo = NULL;
    noh->anterior = NULL;
    return noh;    
}

void criarLista(Lista *lista, int nr){
    lista->inicio = criarNode(nr);
    lista->tamanho++;
}

void inserirNoInicio(Lista *lista, int nr){
    node *noh;
    noh = criarNode(nr);
    lista->inicio->anterior = noh;
    noh->proximo = lista->inicio;
    noh->anterior = NULL;
    lista->inicio = noh;    
    lista->tamanho++;
}

void inserirNoFim(Lista *lista, int nr){
    node *noh =  lista->inicio;
    node *novoNoh;
    novoNoh = criarNode(nr);

    while(noh->proximo != NULL)
        noh = noh->proximo;
    
    noh->proximo = novoNoh;
    novoNoh->proximo = NULL;
    novoNoh-> anterior = noh;
    lista->tamanho++;
}

void retirarDoInicio(Lista *lista){
    node *noh = lista->inicio;
    if(lista->tamanho > 1){
        printf("\nItem retirado da lista: %d\n",noh->valor);
        lista->inicio = noh->proximo;
        noh->proximo->anterior = NULL;
        lista->tamanho--;
        free(noh);
    } else {
        printf("\nLista so tem um item. Nao estou autorizado a retirar o ultimo item.\n");
    }
}

void retirarDoFim(Lista *lista){
    node *noh = lista->inicio;
    if(lista->tamanho > 1){
        for(int i=1; i < lista->tamanho - 1; i++){
            noh = noh->proximo;
        }
        printf("\nItem retirado: %d\n",noh->proximo->valor);
        free(noh->proximo);
        noh->proximo = NULL;
        lista->tamanho--;
    } else{
        printf("\nLista so tem um item. Nao estou autorizado a retirar o ultimo item.\n");
    }   
} 

void retirarItem(Lista *lista, int n){
    node *noh = lista->inicio;
    int indice = 1;

    while(noh != NULL){
        if(noh->valor == n){
            printf("\nValor encontrado: %d\n", noh->valor);
            if(indice == 1){
                retirarDoInicio(lista);
                return;
            }
            else if (indice == lista->tamanho){
                retirarDoFim(lista);
                return;
            }
            else{
                noh->anterior->proximo = noh->proximo;
                noh->proximo->anterior = noh->anterior;
                free(noh);
                lista->tamanho--;
                return;
            }
        }  
        noh = noh->proximo;      
        indice++;
    }
    printf("\nValor nao encontrado na lista.\n");
}

void printDadosDaLista(Lista lista){
    printf("\nEndereco do inicio da lista : %p\n", lista.inicio);
    printf("Tamanho da lista            : %d\n", lista.tamanho);
    printf("\n");
}

void printLista(Lista lista){
    node *noh =  lista.inicio;  
    printf("\nINICIO:");     
    while(noh != NULL){
        printf("%d:", noh->valor);
        noh = noh->proximo;        
    }
    printf("FIM\n"); 
}

void freeLista(Lista lista){
    node *noh = lista.inicio;
    while(noh != NULL){
        free(noh);
        lista.tamanho--;
        noh = noh->proximo;
    }
}
