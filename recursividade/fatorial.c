/*
Fatorial de n é definido como o produto de todos os inteiros entre n
e 1. O fatorial de zero é definido como 1.

Exemplo: Fatorial de 5, indicado por 5!, é igual a 5 * 4 * 3 * 2 * 1

5! = 5 * 4 * 3 * 2 * 1 = 120

Assim podemos definir:

0! = 1
n! = n * (n-1) * (n-2) * ... * 1 se n > 0

Das definiçõe acima podemos concluir que:

0! = 1
1! = 1 * 1
2! = 2 * 1
3! = 3 * 2 * 1
4! = 4 * 3 * 2 * 1
5! = 5 * 4 * 3 * 2 * 1
.......

Observe que podemos fazer as substituições mostradas abaixo:

0! = 1
1! = 1 * 0!
2! = 2 * 1!
3! = 3 * 2!
4! = 4 * 3!
5! = 5 * 4!
.......

E do exposto acima podemos deduzir que:

0! = 1
n! = n * (n - 1)!

Referências:
TANENBAUM, A. M.;LANGSAM, Y.;AUGENSTEIN, M. J. Estruturas de Dados Usando C. São Paulo: Pearson Makron Books, 1995.

arataca89@gmail.com
20210609
*/
#include <stdio.h>

/* função fatorial interativa */
int intFatorial(int n){
    int fatorial = 1;;
    if(n == 0){
        return 1;
    }
    for(int i=1; i<=n; i++){
        fatorial *= i;
    }
    return fatorial;
}

/* função fatorial recursiva */
int recFatorial(int n){
    if(n == 0){
        return 1;
    }
    return(n * recFatorial(n - 1));
}

int main(){
    printf("intFatorial: %d\n", intFatorial(5));
    printf("recFatorial: %d\n", recFatorial(5));
    return 0;
}
