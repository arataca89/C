/*
narcissistic.c

arataca89@gmail.com

CodeWars exercise:

A Narcissistic Number is a positive number which is the sum of its
own digits, each raised to the power of the number of digits in a
given base. In this Kata, we will restrict ourselves to decimal
(base 10).

For example, take 153 (3 digits), which is narcisstic:

    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
and 1652 (4 digits), which isn't:

    1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
The Challenge:

Your code must return true or false depending upon whether the given
number is a Narcissistic number in base 10.

Error checking for text strings or other invalid inputs is not required,
only valid positive non-zero integers will be passed into the function.

TESTS:
153, True
201, False
259, False
371, True
407, True
595, False
825, False
1634, True
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


bool narcissistic(int num){
    float quociente=1.0;
    float divisor = 1.0;
    float base,total=0.0;
    int aux,i,dez = 1;
	 
	aux = num;
	    
    for(;;){
    	if(quociente < 1.0) break;
    	quociente = num/divisor;
    	divisor *= 10;
    	dez++;
   	    //printf("%d / %.2f = %.2f\n",num,divisor,quociente);
	}  
	dez-=3;
	//printf("fator dez: %d\n",dez);
	
	for(i=dez;i>=0;i--){
		base = floor( aux/pow(10,i) );
        //printf("base: %f\n",base);
        total += pow(base,dez+1);
        aux -= base*pow(10,i);
	}
    //printf("total: %f\n",total);
    
    if(total == (float)num){
        return true;    	
	}
	else{
		return false;
	}
}


int main(){
	int n=1;
	
	for(;;){
	    printf("Entre com o numero ou -1 para encerrar: ");
	    scanf("%d",&n);	
	    if(n<0) return 0;
	    if(narcissistic(n)){
		  printf("true\n");
	    }  
	    else{
		    printf("false\n");
	    }
    }
    
	return 0;
}

/* end of narcissistic.c */
