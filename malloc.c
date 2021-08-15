/********************************************************************
Nome: malloc.c
Descrição: Alocação dinãmica de memória usando malloc() e free()
Data: 20210526

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 


A função malloc() é usada para alocar memória dinamicamente.
Ela pertence ao arquivo de cabeçalho stdlib.h
malloc() retorna um ponteiro void para a memória alocada ou NULL em caso de erro.
Como retorna um ponteiro do tipo void, este deve ser convertido no tipo desejado.
Quando a memória alocada não for mais necessária deve ser liberada com free().

Como usar malloc():

ptr = (cast-type*) malloc(qtde * sizeof(type));
if(ptr == NULL)
    ERRO; 
................................................................
................................................................
................................................................
free(ptr);


Referências:
SCHILDT, H. C Completo e Total. 3a Edição. São Paulo: Makron Books, 1996.
DEITEL, P; DEITEL, H. C Como Programar. 6a Edição. São Paulo: Pearson Prentice Hall: 2011
https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
http://www.cplusplus.com/reference/cstdlib/malloc/

********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(){

    int* ptr;
    int i;

    ptr = (int*)malloc(SIZE * sizeof(int));

    if(ptr == NULL){
        printf("Erro na alocacao de memoria.\n");
        exit(0);
    }

    /* chegando aqui a memória foi alocada com sucesso */
    printf("Memoria alocada com sucesso.\n");

    /* colocando valores no vetor int */
    for(i = 0; i < SIZE; i++){
        ptr[i] = i+1;
    }

    /* exibindo o vetor */
    for(i = 0; i < SIZE; i++){
        printf("%d, ", ptr[i]);
    }
    printf("\n");

    /* não esquecer de liberar a memória alocada */
    free(ptr);
    printf("Memoria liberada\n");

    return 0;
}
/********************************************************************

SAÍDA:

Memoria alocada com sucesso.
1, 2, 3, 4, 5,
Memoria liberada

arataca89@gmail.com
Aulas particulaes de programação em C/C++ 
********************************************************************/
