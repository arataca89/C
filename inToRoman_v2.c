/*
intToRoman_v2.c - Esta versão tem alocação dinâmica de memória

arataca89@gmail.com

CodeWars exercise:

Create a function taking a positive integer as its parameter and
returning a string containing the Roman Numeral representation
of that integer.

Modern Roman numerals are written by expressing each digit separately
starting with the left most digit and skipping any digit with a value
of zero. 

In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting
in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses
each Roman symbol in descending order: MDCLXVI.

Example:

solution(1000); // => "M"
Help:

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000

Remember that there can't be more than 3 identical symbols in a row.

Referência: https://escolakids.uol.com.br/matematica/numeros-romanos-2.htm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(int n);
char *milhar(int n);
char *centena(int n);
char *dezena(int n);
char *unidade(int n);
void error();

void test(int i, char *r);
void tests();


int main(){
    int nr_int;
	char *nr_roman;
	
	//printf("Entre com um inteiro entre 0 e 3999: ");
	//scanf("%d",&nr_int);
	
	//if(nr_int < 0 || nr_int>3999) error();
	
	tests();
	
	nr_roman = solution(nr_int);

	return 0;
}


char *solution(int n) { 
   
    char buff[50] = "";		
	int p1,p2,p3,p4;
	int aux,q;
	char *r1,*r2,*r3,*r4;
	char *roman_nr;
	
	q = n/1000;
	p1 = q*1000;
	aux = n-p1;
	r1 = milhar(p1);

	q = aux/100;
	p2 = q*100;
	aux = aux-p2;
	r2 = centena(p2);
	
	q = aux/10;
	p3 = q*10;
	r3 = dezena(p3);
	p4 = aux-p3;
	r4 = unidade(p4);	

	strcat(buff,r1);
	strcat(buff,r2);
	strcat(buff,r3);
	strcat(buff,r4);

    roman_nr = malloc(strlen(buff)+1);
    if(!roman_nr){
    	printf("Memory allocation error.\n");
    	exit(1);
	}
	
	for(int i=0;i<strlen(buff);i++){
		*roman_nr++ = buff[i];
	}
    *roman_nr = '\0';
    roman_nr -= strlen(buff);  
    return roman_nr;    
}


char *milhar(int n){
	switch(n){
		case 0:
			return "";
		case 1000:
			return "M";
		case 2000:
			return "MM";
		case 3000:
			return "MMM";
		default:
			error();
    }
}


char *centena(int n){
	switch(n){
		case 0:
			return "";
		case 100:
			return "C";
		case 200:
			return "CC";
		case 300:
			return "CCC";
		case 400:
			return "CD";
		case 500:
			return "D";
		case 600:
			return "DC";
		case 700:
			return "DCC";
		case 800:
			return "DCCC";
		case 900:
			return "CM";
    }
}


char *dezena(int n){
	switch(n){
		case 0:
			return "";
		case 10:
			return "X";
		case 20:
			return "XX";
		case 30:
			return "XXX";
		case 40:
			return "XL";
		case 50:
			return "L";
		case 60:
			return "LX";
		case 70:
			return "LXX";
		case 80:
			return "LXXX";
		case 90:
			return "XC";
    }
}


char *unidade(int n){
	switch(n){
		case 0:
			return "";
		case 1:
			return "I";
		case 2:
			return "II";
		case 3:
			return "III";
		case 4:
			return "IV";
		case 5:
			return "V";
		case 6:
			return "VI";
		case 7:
			return "VII";
		case 8:
			return "VIII";
		case 9:
			return "IX";
    }
}


void error(){
	printf("ERROR. Number out of interval. Must be: 0 <= number <= 3999.\n");
	exit(1);	
}


/* TESTES */


void test(int i, char *r){	
    char *p = "";    
    char *s = solution(i); 
    
    //printf("s: %s\n",s);
    //printf("r: %s\n",r);
    //printf("strcmp: %d\n",strcmp(s,r));
    //printf("strlen s: %d\n",strlen(s));
    //printf("strlen r: %d\n",strlen(r));

	if( !strcmp(s,r)){
		printf("OK\n");		
	}
	else{
		printf("ERRO\n");
	}
	       
	*s = *p;

}

void tests(){
	printf("testes - inicio\n");

	test(1,"I");
	test(4,"IV");
	test(1000,"M");
	test(1990,"MCMXC");
	test(2007,"MMVII");	
	test(2,"II");
	test(3,"III");
	test(5,"V");
	test(9,"IX");
	test(10,"X");
	test(11,"XI");
	test(15,"XV");
	test(19,"XIX");
	test(22,"XXII");
	test(1001,"MI");
	test(2008,"MMVIII");
	test(1004,"MIV");
	test(2004,"MMIV");
	test(3003,"MMMIII");
	test(1991,"MCMXCI");
	test(1992,"MCMXCII");
	test(2091,"MMXCI");
	test(1996,"MCMXCVI");
	test(2843,"MMDCCCXLIII");
	test(964,"CMLXIV");
	test(345,"CCCXLV");
	test(979,"CMLXXIX");
	test(746,"DCCXLVI");
	test(390,"CCCXC");
	test(376,"CCCLXXVI");
	test(189,"CLXXXIX");
	printf("testes - fim\n");
}

  
/* end of intToRoman_v2.c */
