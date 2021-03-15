/*
int_qtde.c

arataca89@gmail.com

Exercício:

Crie uma função que recebe um array de inteiros e retorna o número do array
ocorre mais vezes.

Considera-se que a entrada é um array que não tem dois números
com a mesma ocorrência máxima.

Exemplos:
int_qtde( {9,9,4,2,2,2,3,3,7,5} ) retorna 2
int_qtde( {9,9,9,9,2,4,3,3,7,5} ) retorna 9
*/

#include <stdio.h>

int int_qtde(const int *nums, size_t n){
	int i,j,x,maior,qtde[n],cont=0;
	int r;
	
	for(i=0;i<n;i++){
		x = nums[i];
		for(j=0;j<n;j++){
			if(nums[j] == x)
			    cont++;
		}
		qtde[i] = cont;
		cont=0;
	}
	/*
	for(i=0;i<n;i++)
		printf("%d ",nums[i]);
	printf("\n");
	
    for(i=0;i<n;i++)
		printf("%d ",qtde[i]);
	printf("\n");
	*/
	maior=qtde[0];
	for(i=1;i<n;i++)
		if(qtde[i] > maior)
		    maior = qtde[i];
	//printf("maior = %d\n",maior);
	
	for(i=0;i<n;i++)
	    if(qtde[i] == maior)
		    r = nums[i];	    
		   
	return r;
}


int main(){
	
	// TESTES (2)
	int numeros[5][10] = { {9,9,4,2,2,2,3,3,7,5},
	                       {9,9,9,9,2,4,3,3,7,5},
	                       {0,9,1,9,2,1,3,1,7,1},
	                       {0,9,0,0,2,4,0,0,7,5},
	                       {-3,9,-3,9,2,-3,-3,0,7,5} };
                       
   // TESTES (1)
   //int numeros[10] = {9,9,4,2,2,2,3,3,7,5};
   //int numeros[10] = {9,9,9,9,2,4,3,3,7,5};
	
	int i,j,n;
	
	/* TESTES (1)	
	n = int_qtde(numeros,10);
	
	for(i=0;i<10;i++)
	    printf("%d ", numeros[i]);
	printf("; maior ocorrencia: %d\n",n);
    */
	
	// TESTES (2)
	for(i=0;i<5;i++){
		n = int_qtde(numeros[i],10);
		for(j=0;j<10;j++)
	        printf("%d ",numeros[i][j]);
		printf(" ; maior ocorrencia: %d\n",n);	
			
	}	 
	
	return 0;
}
// fim de int_qtde.c
 
