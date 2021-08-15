/********************************************************************
Nome: array_insert_in_order.c
Descrição: Demonstra como inserir elementos em ordem crescente num
           array de inteiros.
Data: 20210815

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 
********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7 /* Ajusta o número de elementos do array */
int array[SIZE]; /* Cria o array */
int qtde = -1; /* Controla a quantidade de elementos inseridos */

/* PROTÓTIPOS DAS FUNÇÕES */
void init();
void print();
int is_full();
void input();
void insert(int n);
void copy(int i, int j);
/***************************/


/* Inicializa o array com valor zero */
void init(){
    for(int i = 0; i < SIZE; i++){
        array[i] = 0;
    }
}


/* Exibe o array na tela */
void print(){
    printf("{");
    for(int i = 0; i < SIZE; i++){
        printf("%d", array[i]);
        if(i < SIZE - 1) printf(",");
    }
    printf("}\n");
}


/* Verifica se o array está cheio */
int is_full(){
    return qtde >= SIZE - 1;
}


/* Processa a entrada de dados */
void input(){
    int n;
    while(!is_full()){
        printf("Entre com o inteiro: ");
        scanf("%d", &n);
        while(getchar() != '\n');
        insert(n);
        print();
    }  
}


/* Copia array[i] para array[j] */
void copy(int i, int j){
    array[j] = array[i];
}


/* Insere um elemento no array na ordem crescente */
void insert(int n){
    int i;
    for(i = 0; i < SIZE; i++){
        if(array[i] <= n && array[i] != 0){
            continue;
        } 
        else if(array[i] == 0){
            array[i] = n;
            qtde++;
            return;
        }
        else{
            for(int j = SIZE - 1; j > i; j--){
                copy(j - 1, j);
            }
            array[i] = n;
            qtde++;
             return;
        }
    }    
}

int main(){
    init();
    input();
    return 0;   
}

/********************************************************************
 SAÍDA:
Entre com o inteiro: 5
{5,0,0,0,0,0,0}
Entre com o inteiro: 13
{5,13,0,0,0,0,0}
Entre com o inteiro: 1
{1,5,13,0,0,0,0}
Entre com o inteiro: 7
{1,5,7,13,0,0,0}
Entre com o inteiro: 3
{1,3,5,7,13,0,0}
Entre com o inteiro: -2
{-2,1,3,5,7,13,0}
Entre com o inteiro: 0
{-2,0,1,3,5,7,13}
 
arataca89@gmail.com
Aulas particulaes de programação em C/C++ 
********************************************************************/
