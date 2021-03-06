/* 
bolha_pior_caso.c 

arataca89@gmail.com

ordenação pelo método da bolha, pior caso
*/

#include <stdio.h>
#include <time.h>
#include <locale.h>


int passagens = 0;
int trocas = 0;
int comparacoes = 0;

int size = 11;
int numeros[11]={10,9,8,7,6,5,4,3,2,1,0};

void bolha(int array[]);
void print_array(int array[]);


int main(){
	setlocale(LC_COLLATE,"");
	setlocale(LC_CTYPE,"");
	
    int contador;
    
    printf("\nOrdenação pelo método da bolha no pior caso.\n");
    printf("Array não ordenado: ");
    print_array(numeros);
    printf("ordenando...\n");
	bolha(numeros);	
	printf("\n");
    printf("Array ordenado: ");
	print_array(numeros);	
	printf("\n%d números; %d passagens; %d comparações, %d trocas\n",size,passagens,comparacoes,trocas);
	return 0;
}


void bolha(int array[]){
	int i,j;
	int c;
	
	for(i=1;i<size;i++){
	    passagens++;
	    printf("\npassagem %d:\n",passagens);
	    for(j=size-1;j>=1;j--){
	    	if(array[j-1]>array[j]){
	    		comparacoes++;
	    		/* troca */
	    		trocas++;
	    		printf("troca: %d - ",trocas);
	    		c = array[j-1];
	    		array[j-1]=array[j];
	    		array[j]=c;
	    		print_array(numeros);
			}
		}
	}
}


void print_array(int array[]){
	int contador;
	for(contador = 0; contador < size; contador++){
		printf("%02d ", array[contador] );
    }
	printf("\n");	
}
/* fim de bolha_pior_caso.c */
