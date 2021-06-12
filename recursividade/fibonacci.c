/*
A sequência de Fibonacci é uma sequência de números inteiros que
normalmente começa com 0 e 1 e onde cada número é o resultado da
soma dos dois números anteriores.

0,1,1,2,3,5,8,13,.....

A sequência de Fibonacci pode ser definida recursivamente por:

F(n) = F(n-1) + F(n-2)

sendo: F(0) = 1 e F(1) = 1


Referências:
TANENBAUM, A. M.;LANGSAM, Y.;AUGENSTEIN, M. J. Estruturas de Dados Usando C. São Paulo: Pearson Makron Books, 1995.
https://pt.wikipedia.org/wiki/Sequência_de_Fibonacci

arataca89@gmail.com
20210612
*/
#include <stdio.h>

void intFibonacci(int i){
    int n1 = 0;
    int n2 = 1;
    int n = n1 + n2;
    printf("%d, %d, %d, ",n1, n2, n);
    while(n <= i){
        n1 = n2;
        n2 = n;        
        n = n1 + n2;
        if(n < i)
            printf("%d, ",n);
    }
}

int recFibonacci(int i){
    int n;
    if(i == 1){        
        return 1;
    }
    if(i == 0){
        return 0;
    }
    n = recFibonacci(i-1) + recFibonacci(i-2);    
    i--;
    return n;
}

int main(){
    int n;

    printf(">>> Sequencia de Fibonacci <<<\n");

    printf("Funcao interativa:\n");
    intFibonacci(3000);

    printf("\nFuncao recursiva:\n");
    for(int i=0; i < 20; i++){
        n = recFibonacci(i);
        printf("recFibonacci(%d): %d\n", i, n);
    }

    return 0;
}

/*

SAIDA:

>>> Sequencia de Fibonacci <<<
Funcao interativa:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
Funcao recursiva:
recFibonacci(0): 0
recFibonacci(1): 1
recFibonacci(2): 1
recFibonacci(3): 2
recFibonacci(4): 3
recFibonacci(5): 5
recFibonacci(6): 8
recFibonacci(7): 13
recFibonacci(8): 21
recFibonacci(9): 34
recFibonacci(10): 55
recFibonacci(11): 89
recFibonacci(12): 144
recFibonacci(13): 233
recFibonacci(14): 377
recFibonacci(15): 610
recFibonacci(16): 987
recFibonacci(17): 1597
recFibonacci(18): 2584
recFibonacci(19): 4181

*/
