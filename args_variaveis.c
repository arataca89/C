/* 
Função que recebe número variável de argumentos

arataca89@gmail.com - Aulas C/C++, Go, Python

*/ 
#include <stdio.h>
#include <stdarg.h> 
#include <math.h> // isnan

double maior(double n, ...);

int main(){
    printf("%.0f\n", maior(-1., -8., -2., -3., NAN)); // -1
    printf("%.0f\n", maior(4., 7., 9., 11., 7., NAN)); // 11
    printf("%.2f\n", maior(1.3, 0.7, 2.5, 5.3, 0.5, -5.1, 1.9, NAN));// 5.3 
    return 0;     
}

/* Recebe números double e retorna o maior */
double maior(double n, ... ){
    double maior;
    va_list nrs;
    va_start(nrs,n);
    maior = va_arg(nrs,double);

    for( ; !isnan(n); n = va_arg(nrs,double)){
        if( n  > maior)
            maior = n; 
    }

    va_end(nrs);
    return maior;
}
