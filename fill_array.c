/*
fill_array.c

arataca89@gmail.com

Exercício:

Escrever função que devolve um ponteiro para um array de números
inteiros preenchidos aleatoriamente.

A função deve receber dois argumentos inteiros, o primeiro define
o limite dos números aleatórios a serem gerados, ou seja, o número mais
alto que pode ser gerado; o segundo define a quantidade de elementos
do array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *fill_array(int limite, int size){
    int i,n;
    int *buffer;
    
	srand( time(NULL) ); // semeia o gerador de números aleatórios

    // aloca memória dinâmicamente
    buffer = (int*)malloc(sizeof(int) * size);
    
    // verifica se a alocação funcionou beleza
    if(!buffer){
    	printf("erro de alocacao de memoria\n");
    	exit(EXIT_FAILURE);
	}
	
	
	for(i=1;i<=size;i++){
		n = ( 1 + ( rand() % limite ));// gera o número aleatório
	    *buffer = n;// armazena o número gerado 
        buffer++;// aponta para a próxima posição de memória
	}	    

    buffer = buffer - size;// volta o ponteiro para o início do array
	 	
	return buffer;// retorna o ponteiro
}


int main(){
	int limite = 100;
	int size = 5;
	int i, *array;
	
	array = fill_array(limite,size);
	
	for(i=1;i<=size;i++)
	    printf("%d ",*array++);
	    
	free(array);
	return 0;
}

//fim de fill.array.c
