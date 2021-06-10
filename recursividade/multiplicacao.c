/*
A multiplicação de um número por outro pode ser definida
das seguintes formas:

2 * 5 = 10

versão interativa: 2 + 2 + 2 + 2 + 2 = 10   

versão recursiva: 

2 * 1 = 2
2 * 2 = 2 * 1 + 2 = 4
2 * 3 = 2 * 2 + 2 = 6
2 * 4 = 2 * 3 + 2 = 8
2 * 5 = 2 * 4 + 2 = 10

a * b = a * (b - 1) + a

Referências:
TANENBAUM, A. M.;LANGSAM, Y.;AUGENSTEIN, M. J. Estruturas de Dados Usando C. São Paulo: Pearson Makron Books, 1995.

arataca89@gmail.com
20210610
*/
#include <stdio.h>

/* Multiplicação de dois números versão interativa */
int intMultiplica(int a, int b){
    int m = 0;
    if(a == 0 || b == 0){
        return 0;
    }
    for(int i=1; i <= b; i++){
        m += a;
    }
    return m;
}

int recMultiplica(int a, int b){
    int m = 0;
    if(a == 0 || b == 0){
        return 0;
    }    
    return recMultiplica(a,(b - 1)) + a; 
}



int main(){
    printf("%d\n",intMultiplica(2,0));
    printf("%d\n",recMultiplica(2,0));
    printf("%d\n",intMultiplica(2,5));
    printf("%d\n",intMultiplica(3,4));
    printf("%d\n",recMultiplica(2,5));
    printf("%d\n",recMultiplica(3,4));
    return 0;
}
